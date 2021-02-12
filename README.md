# CubedProgrammerCDateTime
A library for manipulating date and time written in C, for windows and linux.

Compile the two source files into a shared library, link ntdll.dll on Windows.

gcc -O3 -I./include -I./header_only_include -c cpcdt_time_epoch.c -fPIC

gcc -O3 -I./include -I./header_only_include -c cpcdt_date_struct.c -fPIC

gcc -shared -o libcpcdt.so cpcdt_time_epoch.o cpcdt_date_struct.o

Remember -lntdll on Windows.
