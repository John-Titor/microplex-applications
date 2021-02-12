// https://github.com/zserge/pt
//
// Cut down to just what'll work for this project.
//
#ifndef PT_H
#define PT_H

#include <stddef.h>

/* Protothread status values */
#define PT_STATUS_BLOCKED   0
#define PT_STATUS_FINISHED  -1
#define PT_STATUS_YIELDED   -2

/* Helper macros to generate unique labels */
#define _pt_line3(name, line) _pt_##name##line
#define _pt_line2(name, line) _pt_line3(name, line)
#define _pt_line(name) _pt_line2(name, __LINE__)

/* empty cases in switches can cause this */
#pragma disable_warning 110

/* endless loops in pt's can cause this */
#pragma disable_warning 126

/*
 * Local continuation based on switch/case and line numbers.
 *
 * Pros: works with any C99 compiler, most simple implementation.
 * Cons: doesn't allow more than one label per line, doesn't preserve local
 * variables.
 */
struct pt {
    unsigned int  label;
    signed char   status;
};
#define pt_init()                                                               \
    { .label = 0, .status = 0 }
#define pt_begin(pt)                                                            \
    switch ((pt)->label) {                                                      \
    case 0:
#define pt_label(pt, stat)                                                      \
    do {                                                                        \
        (pt)->label = __LINE__;                                                 \
        (pt)->status = (stat);                                                  \
    case __LINE__:;                                                             \
    } while (0)
#define pt_end(pt)                                                              \
    pt_label(pt, PT_STATUS_FINISHED);                                           \
    }

/*
 * Core protothreads API
 */
#define pt_status(pt) (pt)->status

#define pt_running(pt) (pt_status(pt) != PT_STATUS_FINISHED)

#define pt_wait(pt, cond)                                                       \
    do {                                                                        \
        pt_label(pt, PT_STATUS_BLOCKED);                                        \
        if (!(cond)) {                                                          \
            return;                                                             \
        }                                                                       \
    } while (0)

#define pt_yield(pt)                                                            \
    do {                                                                        \
        pt_label(pt, PT_STATUS_YIELDED);                                        \
        if (pt_status(pt) == PT_STATUS_YIELDED) {                               \
            (pt)->status = PT_STATUS_BLOCKED;                                   \
            return;                                                             \
        }                                                                       \
    } while (0)

#define pt_exit(pt, stat)                                                       \
    do {                                                                        \
        pt_label(pt, stat);                                                     \
        return;                                                                 \
    } while (0)

#define pt_loop(pt, cond)                                                       \
    for (int _intr = 0; _intr == 0;)                                            \
        if (1) {                                                                \
            pt_label(pt, PT_STATUS_BLOCKED);                                    \
            if (!(cond)) {                                                      \
                break;                                                          \
            }                                                                   \
            goto _pt_line(body);                                                \
        } else                                                                  \
            while (1)                                                           \
                if (1) {                                                        \
                    _intr = 1;                                                  \
                    break;                                                      \
                } else                                                          \
                    while (1)                                                   \
                        if (1) {                                                \
                            return;                                             \
                        } else                                                  \
                            _pt_line(body) :

/*
 * Queues
 */
#define pt_queue(T, size)                                                       \
    struct {                                                                    \
        T buf[size];                                                            \
        unsigned int r;                                                         \
        unsigned int w;                                                         \
    }
#define pt_queue_init()                                                         \
    { .r = 0, .w = 0 }
#define pt_queue_len(q) (sizeof((q)->buf) / sizeof((q)->buf[0]))
#define pt_queue_cap(q) ((q)->w - (q)->r)
#define pt_queue_empty(q) ((q)->w == (q)->r)
#define pt_queue_full(q) (pt_queue_cap(q) == pt_queue_len(q))
#define pt_queue_reset(q) ((q)->w = (q)->r = 0)

#define pt_queue_push(q, el)                                                    \
    (!pt_queue_full(q) && ((q)->buf[(q)->w++ % pt_queue_len(q)] = (el), 1))
#define pt_queue_peek(q)                                                        \
    (pt_queue_empty(q) ? NULL : &(q)->buf[(q)->r % pt_queue_len(q)])
#define pt_queue_pop(q)                                                         \
    (pt_queue_empty(q) ? NULL : &(q)->buf[(q)->r++ % pt_queue_len(q)])

#endif /* PT_H */