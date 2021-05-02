#ifndef __cplusplus
#ifndef Included_cpcdt_date_struct_h
#define Included_cpcdt_date_struct_h
#include<cpcdt_time_epoch.h>

#define CPCDT_FIELD_SEC 997
#define CPCDT_FIELD_MIN 998
#define CPCDT_FIELD_HOUR 999
#define CPCDT_FIELD_DAY 1000
#define CPCDT_FIELD_MONTH 1001
#define CPCDT_FIELD_YEAR 1002

#define CPCDT____UTC 69
#define CPCDT_NTWELVE_TIME 997
#define CPCDT_ASAMOA_TIME 998
#define CPCDT_HONOLULU_TIME 999
#define CPCDT_FRPOLYNESIA_TIME 1000
#define CPCDT_ALASKA_TIME 1001
#define CPCDT_LA_TIME 1002
#define CPCDT_EDMONTON_TIME 1003
#define CPCDT_CHICAGO_TIME 1004
#define CPCDT_TORONTO_TIME 1005
#define CPCDT_HALIFAX_TIME 1006
#define CPCDT_NEWFOUNDLAND_TIME 1007
#define CPCDT_SAUPAULO_TIME 1008
#define CPCDT_SGEORGIA_TIME 1009
#define CPCDT_CAPEVERDE_TIME 1010
#define CPCDT_LONDON_TIME 1011
#define CPCDT_BERLIN_TIME 1012
#define CPCDT_CAIRO_TIME 1013
#define CPCDT_ISTANBUL_TIME 1014
#define CPCDT_TEHRAN_TIME 1015
#define CPCDT_DUBAI_TIME 1016
#define CPCDT_KABUL_TIME 1017
#define CPCDT_KARACHI_TIME 1018
#define CPCDT_MUMBAI_TIME 1019
#define CPCDT_NEPAL_TIME 1020
#define CPCDT_DHAKA_TIME 1021
#define CPCDT_YANGON_TIME 1022
#define CPCDT_JAKARTA_TIME 1023
#define CPCDT_BEIJING_TIME 1024
#define CPCDT_EUCLA_TIME 1025
#define CPCDT_TOKYO_TIME 1026
#define CPCDT_ADELAIDE_TIME 1027
#define CPCDT_SYDNEY_TIME 1028
#define CPCDT_NSWALES_TIME 1029
#define CPCDT_MAGADAN_TIME 1030
#define CPCDT_AUCKLAND_TIME 1031
#define CPCDT_CHATHAMIS_TIME 1032
#define CPCDT_SAMOA_TIME 1033
#define CPCDT_PFOURTEEN_TIME 1034
#define CPCDT_INVALID_MONTH 997
#define CPCDT_INVALID_DAY 998
#define CPCDT_INVALID_HOUR 999
#define CPCDT_INVALID_MINUTE 1000
#define CPCDT_INVALID_SECOND 1001
#define CPCDT_NO_ERROR 0

typedef int cpcdt_timezone_t;
// days of week names
static const char *CPCDT____DWN[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// months of year names
static const char *CPCDT____MYN[] = {"nothing", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

/**
 * Date struct
 */
struct cpcdt____date
{
	cpcdt_sec_t sec;
	cpcdt_min_t min;
	cpcdt_hour_t hr;
	cpcdt_day_t day;
	cpcdt_day_t dayw;
	cpcdt_month_t month;
	cpcdt_year_t year;
	cpcdt_timezone_t timezone;
};
typedef struct cpcdt____date *cpcdt_date;
/**
 * Converts time since epoch to readable date
 */
void cpcdt_get_date(cpcdt_sec_t et, cpcdt_sec_t *sec, cpcdt_min_t *min, cpcdt_hour_t *hr, cpcdt_day_t *day, cpcdt_day_t *dayw, cpcdt_month_t *month, cpcdt_year_t *yr);

/**
 * Makes a malloc'ed date struct from a time
 */
struct cpcdt____date *cpcdt_make_date(cpcdt_sec_t et);

/**
 * Makes a malloc'ed date struct from a time with timezone
 */
struct cpcdt____date *cpcdt_make_date_with_timezone(cpcdt_sec_t et, cpcdt_timezone_t timezone);

/**
 * Get the time since epoch of a date
 */
cpcdt_sec_t cpcdt_get_time(const struct cpcdt____date *date);

/**
 * Get the time since epoch of a date with time zone
 */
cpcdt_sec_t cpcdt_get_time_with_timezone(const struct cpcdt____date *date);

/**
 * Changes timezone of a date
 */
void cpcdt_convert_timezone(struct cpcdt____date *date, cpcdt_timezone_t timezone);

/**
 * Gets the offset of a time zone
 */
cpcdt_sec_t cpcdt_timezone_offset(cpcdt_timezone_t timezone);

/**
 * Makes a date struct from a given date
 */
struct cpcdt____date *cpcdt_make_date_from_date(cpcdt_sec_t sec, cpcdt_min_t min, cpcdt_hour_t hr, cpcdt_day_t day, cpcdt_month_t month, cpcdt_year_t year);

/**
 * Set the value of a date
 */
void cpcdt_set_date(struct cpcdt____date *date, int field, int val);

/**
 * Checks if a date object is okay, returns zero if it is
 */
int cpcdt_is_okay(const struct cpcdt____date *date);

/**
 * Set the value of a date
 */
void cpcdt_set_date_all_fields(struct cpcdt____date *date, cpcdt_sec_t sec, cpcdt_min_t min, cpcdt_hour_t hr, cpcdt_day_t day, cpcdt_month_t month, cpcdt_year_t year);

/**
 * Get the first day of week of a month, for example, first Tuesday of April
 */
struct cpcdt____date *cpcdt_month_dayw(cpcdt_year_t year,cpcdt_month_t month, cpcdt_day_t day);

/**
 * Reads a date in the form of DAY_OF_WEEK, MONTH DAYst/nd/rd/th, YEAR, HR:MIN:SEC
 * DAY_OF_WEEK is actually ignored and will be correctly calculated, that does NOT mean you can exclude it from the string.
 */
struct cpcdt____date *cpcdt_parse_date(const char *ds);

/**
 * Get the difference in seconds of two date objects
 */
static inline cpcdt_sec_t cpcdt_date_diff(const struct cpcdt____date *x, const struct cpcdt____date *y)
{
	return cpcdt_get_time_with_timezone(x) - cpcdt_get_time_with_timezone(y);
}

/**
 * Gets today's date.
 */
static inline struct cpcdt____date *cpcdt_get_today(void)
{
	struct cpcdt____date *date = cpcdt_make_date(sec_since_epoch());
	date->hr = 0;
	date->min = 0;
	date->sec = 0;
	return date;
}

/**
 * Gets yesterday's date
 */
static inline struct cpcdt____date *cpcdt_get_yesterday(void)
{
	struct cpcdt____date *date = cpcdt_make_date(sec_since_epoch() - 86400);
	date->hr = 0;
	date->min = 0;
	date->sec = 0;
	return date;
}

/**
 * Gets tomorrow's date
 */
static inline struct cpcdt____date *cpcdt_get_tomorrow(void)
{
	struct cpcdt____date *date = cpcdt_make_date(sec_since_epoch() + 86400);
	date->hr = 0;
	date->min = 0;
	date->sec = 0;
	return date;
}

/**
 * Gets today's date.
 */
static inline struct cpcdt____date *cpcdt_get_today_with_timezone(cpcdt_timezone_t tz)
{
	struct cpcdt____date *date = cpcdt_make_date(sec_since_epoch() + cpcdt_timezone_offset(tz));
	date->hr = 0;
	date->min = 0;
	date->sec = 0;
	return date;
}

/**
 * Gets yesterday's date
 */
static inline struct cpcdt____date *cpcdt_get_yesterday_with_timezone(cpcdt_timezone_t tz)
{
	struct cpcdt____date *date = cpcdt_make_date(sec_since_epoch() - 86400 + cpcdt_timezone_offset(tz));
	date->hr = 0;
	date->min = 0;
	date->sec = 0;
	return date;
}

/**
 * Gets tomorrow's date
 */
static inline struct cpcdt____date *cpcdt_get_tomorrow_with_timezone(cpcdt_timezone_t tz)
{
	struct cpcdt____date *date = cpcdt_make_date(sec_since_epoch() + 86400 + cpcdt_timezone_offset(tz));
	date->hr = 0;
	date->min = 0;
	date->sec = 0;
	return date;
}

/**
 * Compares two dates, returns -1 if x comes before y, 1 if y comes before x, and 0 if equal
 */
static inline int cpcdt_compar_date(const struct cpcdt____date *x, const struct cpcdt____date *y)
{
	cpcdt_sec_t xn = cpcdt_get_time_with_timezone(x), yn = cpcdt_get_time_with_timezone(y);
	if(xn < yn)
		return-1;
	else if(xn > yn)
		return 1;
	else
		return 0;
}

/**
 * Gets the name of a month
 */
static inline const char *cpcdt_month_name(cpcdt_month_t month)
{
	return CPCDT____MYN[month];
}

/**
 * Gets the name of a day of the week
 */
static inline const char *cpcdt_day_name(cpcdt_day_t day)
{
	return CPCDT____DWN[day];
}

/**
 * Converts to human readable date and stores it in cbuf
 */
void cpcdt_readable_date(char *cbuf, const struct cpcdt____date *date);

/**
 * Gets the error of the last date parsing call
 */
int cpcdt_get_last_parse_error(void);
#endif
#endif
