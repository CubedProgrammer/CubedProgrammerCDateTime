#ifndef __cplusplus
#ifndef Included_header_only_cpcdt_formatter_h
#define Included_header_only_cpcdt_formatter_h
#include<cpcdt_formatter.h>
int cpcdt_snprintf(char *restrict buf, size_t bufsz, const char *restrict fmt, const struct cpcdt____date *date)
{
	int cnt = 0;
	char ch;
	--bufsz;
	cpcdt_hour_t tmphr;
	cpcdt_year_t tmpyr;
	char yrstr[5];
	for(const char *it = fmt; *it != '\0'; ++it)
	{
		ch = *it;
		if(ch == '%')
		{
			ch = *++it;
			switch(ch)
			{
				case'%':
					if(cnt < bufsz)
						buf[cnt] = ch;
					break;
				case'H':
					if(cnt < bufsz)
						buf[cnt] = '0' + date->hr / 10;
					if(++cnt < bufsz)
						buf[cnt] = '0' + date->hr % 10;
					break;
				case'I':
					tmphr = date->hr % 12;
					if(tmphr == 0)
						tmphr = 12;
					if(cnt < bufsz)
						buf[cnt] = '0' + tmphr / 10;
					if(++cnt < bufsz)
						buf[cnt] = '0' + tmphr % 10;
					break;
					break;
				case'k':
					tmphr = date->hr;
					if(cnt < bufsz)
						buf[cnt] = '0' + tmphr % 10;
					tmphr /= 10;
					if(tmphr)
					{
						if(cnt + 1 < bufsz)
							buf[cnt + 1] = '0' + tmphr;
						buf[cnt] = '0' + tmphr;
						cnt++;
					}
					break;
				case'l':
					tmphr = date->hr % 12;
					if(tmphr == 0)
						tmphr = 12;
					if(cnt < bufsz)
						buf[cnt] = '0' + tmphr % 10;
					tmphr /= 10;
					if(tmphr)
					{
						if(cnt + 1 < bufsz)
							buf[cnt + 1] = '0' + tmphr;
						buf[cnt] = '0' + tmphr;
						cnt++;
					}
					break;
				case'M':
					if(cnt < bufsz)
						buf[cnt] = '0' + date->min / 10;
					if(++cnt < bufsz)
						buf[cnt] = '0' + date->min % 10;
					break;
				case'S':
					if(cnt < bufsz)
						buf[cnt] = '0' + date->sec / 10;
					if(++cnt < bufsz)
						buf[cnt] = '0' + date->sec % 10;
					break;
				case'p':
					if(cnt < bufsz)
						buf[cnt] = date->hr >= 12 ? 'p' : 'a';
					if(++cnt < bufsz)
						buf[cnt] = 'm';
					break;
				case'Y':
					tmpyr = date->year;
					for(int i = 3; i >= 0; --i)
					{
						yrstr[i] = '0' + tmpyr % 10;
						tmpyr /= 10;
					}
					yrstr[4] = '\0';
					for(int i = 0; i < 4; ++i)
					{
						if(cnt < bufsz)
							buf[cnt] = yrstr[i];
						if(i < 3)
							++cnt;
					}
					break;
				case'y':
					tmpyr = date->year % 100;
					if(cnt < bufsz)
						buf[cnt] = '0' + tmpyr / 10;
					if(++cnt < bufsz)
						buf[cnt] = '0' + tmpyr % 10;
					break;
				case'm':
					if(cnt < bufsz)
						buf[cnt] = '0' + date->month / 10;
					if(++cnt < bufsz)
						buf[cnt] = '0' + date->month % 10;
					break;
				case'e':
				if(date->day >= 10)
				{
				case'd':
					if(cnt < bufsz)
						buf[cnt] = '0' + date->day / 10;
					if(++cnt < bufsz)
						buf[cnt] = '0' + date->day % 10;
					break;
				}
				else if(cnt < bufsz)
				{
					buf[cnt] = '0' + date->day;
					break;
				}
				else
					break;
				default:
					if(cnt < bufsz)
						buf[cnt] = '%';
					if(++cnt < bufsz)
						buf[cnt] = ch;
			}
		}
		else
			buf[cnt] = ch;
		++cnt;
	}
	if(cnt < bufsz)
		bufsz = cnt;
	buf[bufsz] = '\0';
	return cnt;
}
#endif
#endif
