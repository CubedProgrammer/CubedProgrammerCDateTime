# CubedProgrammerCDateTime
A library for manipulating date and time written in C.

Compile the two source files into a shared library.

The headers should be put into a directory such as /usr/local/include.

```sh
gcc -O3 -I./include -I./header_only_include -c src/cpcdt_time_epoch.c src/cpcdt_date_struct.c src/cpcdt_formatter.c -fPIC
gcc -shared -o libcpcdt.so cpcdt_time_epoch.o cpcdt_date_struct.o
```

No longer need ntdll.dll for Windows.