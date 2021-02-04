/*
 * MSCAN driver.
 *
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <mc9s08dz60.h>
#include <mscan.h>

static const uint8_t btr_table[][2] = {
    { 0x04, 0x1c }, // 100kHz
    { 0x03, 0x1c }, // 125kHz
    { 0x01, 0x1c }, // 250kHz
    { 0x00, 0x1c }, // 500kHz
    { 0x00, 0x05 }  // 1MHz
};

typedef enum {
    WM_NONE,
    WM_SPACE,
    WM_SENT
} CAN_wait_mode;

static bool _CAN_send(const CAN_message *msg,
                      CAN_wait_mode wait);

void
CAN_init(CAN_bitrate bitrate,
         CAN_filter_mode filter_mode,
         const CAN_filters *filters)
{
    assert(bitrate <= (sizeof(btr_table) / sizeof(btr_table[0])));
    assert(filter_mode <= CAN_FM_NONE);

    // set INITRQ and wait for it to be acknowledged
    CANCTL0 = CANCTL0_INITRQ_MASK;
    while (!(CANCTL1 & CANCTL1_INITAK_MASK)) {
    }

    // enable MSCAN, select external clock
    CANCTL1 = CANCTL1_CANE_MASK;

    // configure for selected bitrate
    CANBTR0 = btr_table[bitrate][0];
    CANBTR1 = btr_table[bitrate][1];

    // configure filters
    if (filter_mode == CAN_FM_NONE) {
        CANIDAC = CANIDAC_IDAM1_MASK; // 8-bit filters
        CANIDAR0 = 0;                 // mask result 0
        CANIDMR0 = 0;                 // look at no bits
    } else {
        CANIDAC = filter_mode << 4;
        CANIDAR0 = filters->filter_8.accept[0];
        CANIDAR1 = filters->filter_8.accept[1];
        CANIDAR2 = filters->filter_8.accept[2];
        CANIDAR3 = filters->filter_8.accept[3];
        CANIDAR4 = filters->filter_8.accept[4];
        CANIDAR5 = filters->filter_8.accept[5];
        CANIDAR6 = filters->filter_8.accept[6];
        CANIDAR7 = filters->filter_8.accept[7];
        CANIDMR0 = filters->filter_8.mask[0];
        CANIDMR1 = filters->filter_8.mask[1];
        CANIDMR2 = filters->filter_8.mask[2];
        CANIDMR3 = filters->filter_8.mask[3];
        CANIDMR4 = filters->filter_8.mask[4];
        CANIDMR5 = filters->filter_8.mask[5];
        CANIDMR6 = filters->filter_8.mask[6];
        CANIDMR7 = filters->filter_8.mask[7];
    }

    // clear INITRQ and wait for it to be acknowledged
    CANCTL0 &= ~CANCTL0_INITRQ_MASK;
    while (CANCTL1 & CANCTL1_INITAK_MASK) {
    }
}

bool
CAN_send(const CAN_message *msg)
{
    assert(msg != NULL);

    // return false if not possible to send immediately.
    return _CAN_send(msg, WM_NONE);
}

void
CAN_send_blocking(const CAN_message *msg)
{
    assert(msg != NULL);

    // wait for space to send message
    _CAN_send(msg, WM_SPACE);
}

void
CAN_send_debug(const CAN_message *msg)
{
    assert(msg != NULL);

    // wait for space and wait for message to be sent -
    // debug messages are thus sent in the order they are
    // queued.
    _CAN_send(msg, WM_SENT);
}

static bool
_CAN_send(const CAN_message *msg,
          CAN_wait_mode wait_mode)
{
    assert(msg != NULL);
    assert(wait_mode <= WM_SENT);

    uint8_t txe;

    // wait for a buffer to be free
    while ((txe = CANTFLG) == 0) {
        // ... or don't
        if (wait_mode == WM_NONE) {
            return false;
        }
    }

    // select the buffer
    CANTBSEL = txe;

    // read back to work out which one we actually selected
    txe = CANTBSEL;

    // copy message to buffer
    CANTIDR0 = msg->id.regs[0];
    CANTIDR1 = msg->id.regs[1];
    CANTIDR2 = msg->id.regs[2];
    CANTIDR3 = msg->id.regs[3];
    CANTDSR0 = msg->data[0];
    CANTDSR1 = msg->data[1];
    CANTDSR2 = msg->data[2];
    CANTDSR3 = msg->data[3];
    CANTDSR4 = msg->data[4];
    CANTDSR5 = msg->data[5];
    CANTDSR6 = msg->data[6];
    CANTDSR7 = msg->data[7];
    CANTDLR = msg->dlc;
    CANTTBPR = msg->priority;

    // mark the buffer as not-empty to start transmission
    CANTFLG = txe;

    // wait for message to send, or don't
    while ((wait_mode == WM_SENT) && !(CANTFLG & txe)) {
    }
    return true;
}

bool
CAN_recv(CAN_message *msg)
{
    assert(msg != NULL);

    (void)msg;
    return false;
}

int
putchar(int c)
{
    static CAN_message msg = {
        .id = { .mscan_id = MSCAN_ID_EXT(0x1ffffffe) },
        .dlc = 0,
        .priority = 128
    };

    // send newline as NUL terminator
    if (c != '\n') {
        msg.data[msg.dlc++] = c;
    } else {
        msg.data[msg.dlc++] = '\0';
    }

    // send message if full or newline
    if ((c == '\n') || (msg.dlc == 8)) {
        CAN_send_debug(&msg);
        msg.dlc = 0;
    }
    return c;
}
