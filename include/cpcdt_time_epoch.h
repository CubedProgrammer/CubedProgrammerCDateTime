#ifndef __cplusplus
#ifndef Included_cpcdt_time_epoch_h
#define Included_cpcdt_time_epoch_h
#include<time.h>
#define CPCDT_MONTH_JAN 1
#define CPCDT_MONTH_FEB 2
#define CPCDT_MONTH_MAR 3
#define CPCDT_MONTH_APR 4
#define CPCDT_MONTH_MAY 5
#define CPCDT_MONTH_JUN 6
#define CPCDT_MONTH_JUL 7
#define CPCDT_MONTH_AUG 8
#define CPCDT_MONTH_SEP 9
#define CPCDT_MONTH_OCT 10
#define CPCDT_MONTH_NOV 11
#define CPCDT_MONTH_DEC 12
#define CPCDT_WEEK_SUN 0
#define CPCDT_WEEK_MON 1
#define CPCDT_WEEK_TUE 2
#define CPCDT_WEEK_WED 3
#define CPCDT_WEEK_THU 4
#define CPCDT_WEEK_FRI 5
#define CPCDT_WEEK_SAT 6
#define cpcdt_nanos_micros(__x__)((__x__) / 1000)
#define cpcdt_nanos_millis(__x__)((__x__) / 1000000)
#define cpcdt_nanos_secs(__x__)((__x__) / 1000000000)
#define cpcdt_nanos_mins(__x__)((__x__) / 60000000000)
#define cpcdt_nanos_hours(__x__)((__x__) / 3600000000000)
#define cpcdt_micros_nanos(__x__)((__x__) * 1000)
#define cpcdt_micros_millis(__x__)((__x__) / 1000)
#define cpcdt_micros_secs(__x__)((__x__) / 1000000)
#define cpcdt_micros_mins(__x__)((__x__) / 60000000)
#define cpcdt_micros_hours(__x__)((__x__) / 3600000000)
#define cpcdt_millis_nanos(__x__)((__x__) * 1000000)
#define cpcdt_millis_micros(__x__)((__x__) * 1000)
#define cpcdt_millis_secs(__x__)((__x__) / 1000)
#define cpcdt_millis_mins(__x__)((__x__) / 60000)
#define cpcdt_millis_hours(__x__)((__x__) / 3600000)
#define cpcdt_secs_nanos(__x__)((__x__) * 1000000000)
#define cpcdt_secs_micros(__x__)((__x__) * 1000000)
#define cpcdt_secs_millis(__x__)((__x__) * 1000)
#define cpcdt_secs_mins(__x__)((__x__) / 60)
#define cpcdt_secs_hours(__x__)((__x__) / 3600)
#define cpcdt_mins_nanos(__x__)((__x__) * 60000000000)
#define cpcdt_mins_micros(__x__)((__x__) * 60000000)
#define cpcdt_mins_millis(__x__)((__x__) * 60000)
#define cpcdt_mins_secs(__x__)((__x__) * 60)
#define cpcdt_mins_hours(__x__)((__x__) / 60)
#define cpcdt_hours_nanos(__x__)((__x__) / 3600000000000)
#define cpcdt_hours_micros(__x__)((__x__) / 3600000000)
#define cpcdt_hours_millis(__x__)((__x__) / 3600000)
#define cpcdt_hours_secs(__x__)((__x__) / 3600)
#define cpcdt_hours_mins(__x__)((__x__) / 60)
typedef long long cpcdt_ns_t;
typedef long long cpcdt_mcs_t;
typedef long long cpcdt_ms_t;
typedef long long cpcdt_sec_t;
typedef int cpcdt_min_t;
typedef int cpcdt_hour_t;
typedef int cpcdt_dayw_t;
typedef int cpcdt_day_t;
typedef int cpcdt_month_t;
typedef int cpcdt_year_t;
static int CPCDT____DAYS_IN_MONTH[] = {69, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
cpcdt_ns_t nsec_since_epoch(void);
time_t sec_since_epoch(void);
int cpcdt_is_leap(cpcdt_year_t yr);
#endif
#endif
