#ifndef __cplusplus
#ifndef Included_cpcdt_date_struct_h
#define Included_cpcdt_date_struct_h
#include<cpcdt_time_epoch.h>
struct cpcdt____date
{
	cpcdt_sec_t sec;
	cpcdt_min_t min;
	cpcdt_hour_t hr;
	cpcdt_day_t day;
	cpcdt_dayw_t dayw;
	cpcdt_month_t month;
	cpcdt_year_t year;
};
typedef struct cpcdt____date *cpcdt_date;
/**
 * Converts time since epoch to readable date
 */
void cpcdt_get_date(cpcdt_sec_t et, cpcdt_sec_t *sec, cpcdt_min_t *min, cpcdt_hour_t *hr, cpcdt_day_t *day, cpcdt_dayw_t *dayw, cpcdt_month_t *month, cpcdt_year_t *yr);
struct cpcdt____date *cpcdt_make_date(cpcdt_sec_t et);
cpcdt_sec_t cpcdt_get_time(const struct cpcdt____date *date);
#endif
#endif
