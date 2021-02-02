#ifndef __cplusplus
#ifndef Included_header_only_cpcdt_date_struct_h
#define Included_header_only_cpcdt_date_struct_h
#include<stdio.h>
#include<stdlib.h>
#include<cpcdt_date_struct.h>

/**
 * Makes a malloc'ed date struct from a time
 */
struct cpcdt____date *cpcdt_make_date(cpcdt_sec_t et)
{
	struct cpcdt____date *date = malloc(sizeof(struct cpcdt____date));
	cpcdt_get_date(et, &date->sec, &date->min, &date->hr, &date->day, &date->dayw, &date->month, &date->year);
	return date;
}

/**
 * Get the time since epoch of a date
 */
cpcdt_sec_t cpcdt_get_time(const struct cpcdt____date *date)
{
	cpcdt_sec_t secs = date->sec + date->min * 60 + date->hr * 3600 + (date->day - 1) * 86400;
	if(cpcdt_is_leap(date->year))
		CPCDT____DAYS_IN_MONTH[CPCDT_MONTH_FEB] = 29;
	for(cpcdt_month_t i = 1; i < date->month; ++i)
		secs += CPCDT____DAYS_IN_MONTH[i] * 86400;
	if(cpcdt_is_leap(date->year))
		CPCDT____DAYS_IN_MONTH[CPCDT_MONTH_FEB] = 28;
	secs += (cpcdt_sec_t)(date->year - 1970) * 31536000;
	// every four years is a leap year
	secs += (cpcdt_sec_t)((date->year - 1969) / 4) * 86400;
	// every one hundred years is not a leap year
	secs -= (cpcdt_sec_t)((date->year - 1901) / 100 + 1) * 86400;
	// every four hundred years is a leap year
	secs += (cpcdt_sec_t)((date->year - 1601) / 400 + 1) * 86400;
	return secs;
}

/**
 * Makes a date struct from a given date
 */
struct cpcdt____date *cpcdt_make_date_from_date(cpcdt_sec_t sec, cpcdt_min_t min, cpcdt_hour_t hr, cpcdt_day_t day, cpcdt_month_t month, cpcdt_year_t year)
{
	struct cpcdt____date *date = malloc(sizeof(struct cpcdt____date));
	date->sec = sec;
	date->min = min;
	date->hr = hr;
	date->day = day;
	date->month = month;
	date->year = year;
	cpcdt_sec_t seconds = cpcdt_get_time(date);
	date->dayw = (seconds / 86400 + 4) % 7;
	return date;
}

/**
 * Set the value of a date
 */
void cpcdt_set_date(struct cpcdt____date *date, int field, int val)
{
	switch(field)
	{
		case CPCDT_FIELD_SEC:
			date->sec = val;
			break;
		case CPCDT_FIELD_MIN:
			date->min = val;
			break;
		case CPCDT_FIELD_HOUR:
			date->hr = val;
			break;
		case CPCDT_FIELD_DAY:
			date->day = val;
			break;
		case CPCDT_FIELD_MONTH:
			date->month = val;
			break;
		case CPCDT_FIELD_YEAR:
			date->year = val;
			break;
	}
	cpcdt_sec_t secs = cpcdt_get_time(date);
	date->dayw = (secs / 86400 + CPCDT_WEEK_THU)  % 7;
}

/**
 * Converts to human readable date and stores it in cbuf
 */
void cpcdt_readable_date(char *cbuf, const struct cpcdt____date *date)
{
	const char *suffix = "th";
	if(date->day == 1 || date->day == 21 || date->day == 31)
		suffix = "st";
	else if(date->day == 2 || date->day == 22)
		suffix = "nd";
	else if(date->day == 3 || date->day == 23)
		suffix = "rd";
	sprintf(cbuf, "%s, %s %d%s, %d, %s%d:%s%d:%s%lld", CPCDT____DWN[date->dayw], CPCDT____MYN[date->month], date->day, suffix, date->year, date->hr < 10 ? "0" : "", date->hr, date->min < 10 ? "0" : "", date->min, date->sec < 10 ? "0" : "", date->sec);
}

/**
 * Converts time since epoch to readable date
 */
void cpcdt_get_date(cpcdt_sec_t et, cpcdt_sec_t *sec, cpcdt_min_t *min, cpcdt_hour_t *hr, cpcdt_day_t *day, cpcdt_day_t *dayw, cpcdt_month_t *month, cpcdt_year_t *yr)
{
	*sec = et % 60;
	*min = et / 60 % 60;
	*hr = et / 3600 % 24;
	long long rday = et / 86400;
	long long fc = rday / 146097;
	long long fcy = rday % 146097;
	long long ct = fcy / 36524;
	long long cty = fcy % 36524;
	if(fcy == 36524 || fcy == 73048 || fcy == 109572 || fcy == 146096)
		ct--;
	if(fcy == 36524)
		cty = 36524;
	else if(fcy > 36524)
		cty = (cty + 36523) % 36524;
	long long fya = cty / 1461, fyb = cty % 1461;
	// every 100 years is not a leap year
	if(ct > 0 && fya == 7 && fyb == 1460)
	{
		fya = 8;
		fyb = 0;
	}
	else if(ct > 0 && fya > 7)
	{
		fyb = (fyb + 1) % 1461;
		if(fyb == 0)
			++fya;
	}
	cpcdt_year_t yf = fyb / 365;
	cpcdt_day_t day_of_year = fyb % 365;
	if(fya != 7 || ct == 0)
	{
		if(fyb == 1095 || fyb == 1460)
			yf--;
		if(fyb == 1095)
			day_of_year = 365;
		else if(fyb > 1095)
			day_of_year = (day_of_year + 364) % 365;
	}
	*yr = fc * 400 + ct * 100 + fya * 4 + yf + 1970;
	if(cpcdt_is_leap(*yr))
		CPCDT____DAYS_IN_MONTH[CPCDT_MONTH_FEB] = 29;
	cpcdt_day_t tot = 0;
	for(cpcdt_month_t i = 1; i <= 12; ++i)
	{
		tot += CPCDT____DAYS_IN_MONTH[i];
		if(tot > day_of_year)
		{
			*month = i;
			i = 13;
			*day = day_of_year - (tot - CPCDT____DAYS_IN_MONTH[*month]) + 1;
		}
	}
	if(cpcdt_is_leap(*yr))
		CPCDT____DAYS_IN_MONTH[CPCDT_MONTH_FEB] = 28;
	// Jan 1st, 1970 was a Thursday
	*dayw = (rday + CPCDT_WEEK_THU) % 7;
}
#endif
#endif
