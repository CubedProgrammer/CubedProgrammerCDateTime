#ifndef __cplusplus
#ifndef Included_header_only_cpcdt_time_epoch_h
#define Included_header_only_cpcdt_time_epoch_h
#include<time.h>
#include<cpcdt_time_epoch.h>
cpcdt_ns_t time_since_epoch(void)
{
	cpcdt_ns_t ns;
#ifdef __linux__
	struct timespec tm;
	clock_gettime(CLOCK_REALTIME, &tm);
	ns = tm.tv_sec * 1000000000 + tm.tv_nsec;
#endif
	return ns;
}
#endif
#endif
