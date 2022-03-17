#ifndef __cplusplus
#ifndef Included_cpcdt_formatter_h
#define Included_cpcdt_formatter_h
#include<stdio.h>
#include<cpcdt_date_struct.h>
int cpcdt_printf(const char *restrict fmt, struct cpcdt____date *date);
int cpcdt_fprintf(FILE *f, const char *restrict fmt, const struct cpcdt____date *date);
int cpcdt_sprintf(char *restrict buf, const char *restrict fmt, const struct cpcdt____date *date);
int cpcdt_snprintf(char *restrict buf, size_t bufsz, const char *restrict fmt, const struct cpcdt____date *date);
#endif
#endif
