#ifndef __cplusplus
#ifndef Included_header_only_cpcdt_time_epoch_h
#define Included_header_only_cpcdt_time_epoch_h
#ifdef _WIN32
#include<windows.h>
#endif
#include<cpcdt_time_epoch.h>
cpcdt_ns_t nsec_since_epoch(void)
{
	cpcdt_ns_t ns;
#ifdef __linux__
	struct timespec tm;
	clock_gettime(CLOCK_REALTIME, &tm);
	ns = tm.tv_sec * 1000000000 + tm.tv_nsec;
#elif defined _WIN32
	SYSTEMTIME tm;
	GetSystemTime(&tm);
	FILETIME ftm;
	SystemTimeToFileTime(&tm, &ftm);
	ULARGE_INTEGER num;
	num.LowPart = ftm.dwLowDateTime;
	num.HighPart = ftm.dwHighDateTime;
	ns = num.QuadPart;
	ns -= 116444736000000000;
	ns *= 100;
#endif
	return ns;
}
time_t sec_since_epoch(void)
{
	return time(NULL);
}
int cpcdt_is_leap(cpcdt_year_t yr)
{
	if(yr % 400 == 0)
		return 1;
	else if(yr % 100 == 0)
		return 0;
	else if(yr % 4 == 0)
		return 1;
	else
		return 0;
}
#endif
#endif
