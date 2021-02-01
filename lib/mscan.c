/*
 * MSCAN driver.
 *
 */

#include <stdint.h>
#include <mc9s08dz60.h>
#include <mscan.h>

static const uint8_t btr_table[][2] = {
    { 0x04, 0x1c }, // 100kHz
    { 0x03, 0x1c }, // 125kHz
    { 0x01, 0x1c }, // 250kHz
    { 0x00, 0x1c }, // 500kHz
    { 0x00, 0x05 }  // 1MHz
};

void
CAN_init(CAN_bitrate bitrate,
        CAN_filter_mode filter_mode,
        const CAN_filters *filters)
{

    // set INITRQ and wait for it to be acknowledged
    _CANCTL0.Byte = CANCTL0_INITRQ_MASK;
    while (!(_CANCTL1.Byte & CANCTL1_INITAK_MASK)) {
    }

    // enable MSCAN, select external clock 
    _CANCTL1.Byte = CANCTL1_CANE_MASK;

    // configure for selected bitrate
    _CANBTR0.Byte = btr_table[bitrate][0];
    _CANBTR1.Byte = btr_table[bitrate][1];

    // configure filters
    if (filter_mode == CAN_FM_NONE) {
        _CANIDAC.Byte = CANIDAC_IDAM1_MASK; // 8-bit filters
        _CANIDAR0.Byte = 0;                 // mask result 0
        _CANIDMR0.Byte = 0;                 // look at no bits
    } else {
        _CANIDAC.Byte = filter_mode << 4;
        _CANIDAR0.Byte = filters->filter_8.accept[0];
        _CANIDAR1.Byte = filters->filter_8.accept[1];
        _CANIDAR2.Byte = filters->filter_8.accept[2];
        _CANIDAR3.Byte = filters->filter_8.accept[3];
        _CANIDAR4.Byte = filters->filter_8.accept[4];
        _CANIDAR5.Byte = filters->filter_8.accept[5];
        _CANIDAR6.Byte = filters->filter_8.accept[6];
        _CANIDAR7.Byte = filters->filter_8.accept[7];
        _CANIDMR0.Byte = filters->filter_8.mask[0];
        _CANIDMR1.Byte = filters->filter_8.mask[1];
        _CANIDMR2.Byte = filters->filter_8.mask[2];
        _CANIDMR3.Byte = filters->filter_8.mask[3];
        _CANIDMR4.Byte = filters->filter_8.mask[4];
        _CANIDMR5.Byte = filters->filter_8.mask[5];
        _CANIDMR6.Byte = filters->filter_8.mask[6];
        _CANIDMR7.Byte = filters->filter_8.mask[7];
    }

    // clear INITRQ and wait for it to be acknowledged
    _CANCTL0.Byte &= ~CANCTL0_INITRQ_MASK;
    while (_CANCTL1.Byte & CANCTL1_INITAK_MASK) {
    }
}

bool CAN_send(const CAN_message *msg)
{
    uint8_t txe = 1;
    
    // which tx buffer are we able to use?
    if (!(_CANTFLG.Byte & txe)) {
        txe <<= 1;
        if (!(_CANTFLG.Byte & txe)) {
            txe <<= 1;
            if (!(_CANTFLG.Byte & txe)) {
                return false;
            }
        }
    }

    // map the buffer
    _CANTBSEL.Byte = txe;

    // copy message to buffer
    _CANTIDR0.Byte = msg->id.regs[0];
    _CANTIDR1.Byte = msg->id.regs[1];
    _CANTIDR2.Byte = msg->id.regs[2];
    _CANTIDR3.Byte = msg->id.regs[3];
    _CANTDSR0.Byte = msg->data[0];
    _CANTDSR1.Byte = msg->data[1];
    _CANTDSR2.Byte = msg->data[2];
    _CANTDSR3.Byte = msg->data[3];
    _CANTDSR4.Byte = msg->data[4];
    _CANTDSR5.Byte = msg->data[5];
    _CANTDSR6.Byte = msg->data[6];
    _CANTDSR7.Byte = msg->data[7];
    _CANTDLR.Byte = msg->dlc;
    _CANTTBPR.Byte = msg->priority;

    // mark the buffer as not-empty to start transmission
    _CANTFLG.Byte = txe;

    return true;
}

bool CAN_recv(CAN_message *msg)
{
    (void)msg;
    return false;
}