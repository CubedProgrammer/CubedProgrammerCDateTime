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
 * Get the time since epoch of a date
 */
cpcdt_sec_t cpcdt_get_time(const struct cpcdt____date *date);

/**
 * Makes a date struct from a given date
 */
struct cpcdt____date *cpcdt_make_date_from_date(cpcdt_sec_t sec, cpcdt_min_t min, cpcdt_hour_t hr, cpcdt_day_t day, cpcdt_month_t month, cpcdt_year_t year);

/**
 * Set the value of a date
 */
void cpcdt_set_date(struct cpcdt____date *date, int field, int val);

/**
 * Set the value of a date
 */
void cpcdt_set_date_all_fields(struct cpcdt____date *date, cpcdt_sec_t sec, cpcdt_min_t min, cpcdt_hour_t hr, cpcdt_day_t day, cpcdt_month_t month, cpcdt_year_t year);

/**
 * Converts to human readable date and stores it in cbuf
 */
void cpcdt_readable_date(char *cbuf, const struct cpcdt____date *date);
#endif
#endif
