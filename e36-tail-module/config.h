/*
 * Configuration parameters.
 */

/* 
 * Timeout (ms) before deciding that CAN has been disconnected.
 */
#define CAN_IDLE_TIMEOUT            500

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
