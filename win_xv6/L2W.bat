rem Batch command to modify source codes for Linux to those for Windows
rem by Hiroshi Uno
rem 
for %%i in (main.c entry.S cat.c echo.c forktest.c grep.c init.c kill.c ln.c ls.c mkdir.c rm.c sh.c stressfs.c usertests.c wc.c, zombie.c) do (
busybox sed -i -r "s/main1?/main1/" %%i
)

busybox sed -i -e "20i #define bzero(b,len) (memset((b), '\\0', (len)), (void) 0)\n#define bcopy(b1,b2,len) (memmove((b2), (b1), (len)), (void) 0)\n#define index(a,b) strchr((a),(b))\n" -e "s/O_CREAT\|O_TRUNC/O_CREAT\|O_BINARY\|O_TRUNC/" -e "s/open(argv\[i\], 0)/open(argv\[i\], O_BINARY)/" mkfs.c

