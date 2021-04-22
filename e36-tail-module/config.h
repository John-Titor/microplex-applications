/*
 * Configuration parameters.
 */

/* 
 * Timeout (ms) before deciding that CAN has been disconnected.
 */
#define CAN_IDLE_TIMEOUT            2000

/* 
 * Interval (ms) between fuel level reports
 */
#define CAN_REPORT_INTERVAL_FUEL    500

/* 
 * Interval (ms) between CAN diagnostic messages.
 * 0 to disable.
 */
#define CAN_REPORT_INTERVAL_DIAGS   1000

/*
 * Interval (ms) between console status reports.
 * 0 to disable.
 */
#define CONSOLE_REPORT_INTERVAL     1000

/*
 * Log interesting things to the console.
 */
#define CONSOLE_DO_LOG

/*
 * Minimum load current (mA): below this, output is considered open.
 */
#define SENSE_OPEN_CURRENT      50

/*
 * Maximum load current (mA): over this, output is considered overloaded.
 */
#define SENSE_OVERLOAD_CURRENT  2500

/*
 * Maximum off voltage (mV): over this, output is considered stuck/shorted to +12.
 */
#define SENSE_STUCK_VOLTAGE     2000

/*
 * Number of successive stuck / overloaded / open tests required to
 * trigger the fault.
 */
#define SENSE_DEBOUNCE_COUNT    3

/*
 * Inrush current settling time (ms)
 */
#define SENSE_INRUSH_DELAY      50

/*
 * Turn-off current settling time (ms)
 */
#define SENSE_SETTLE_DELAY      500

/*
 * Delay between retries for an overloaded output (ms).
 */
#define SENSE_OVERLOAD_RETRY_INTERVAL   1000
