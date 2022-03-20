# Makefile by Uno 2021/08/21

CFLAGS = -fno-pic -static -fno-builtin -fno-strict-aliasing -O2 -Wall -MD -ggdb -m32 -Werror -fno-omit-frame-pointer
# for Windows
CFLAGS += -fno-stack-protector

sign:
	gcc -ggdb -o sign.exe sign.c
sign2:
	gcc $(CFLAGS) -ggdb -fno-leading-underscore -o sign2.exe sign.c
sign3:
	gcc $(CFLAGS) -ggdb -o sign3.exe sign.c
sign4:
	gcc $(CFLAGS) -ggdb -o sign4.o -c sign.c
	ld -o sign4.exe sign4.o
sign5:
	gcc $(CFLAGS) -ggdb -o sign5.o -c sign.c
sign6:
	gcc -ggdb -o sign6.o -c sign.c
sign_trace:
	gcc -Wl,--trace -ggdb -o sign.exe sign.c
sign_v:
	gcc -v -ggdb -o sign.exe sign.c
sign_wrap:
	gcc -wrapper my_wrap.exe -ggdb -o sign.exe sign.c
sign_vwrap:
	gcc -v -wrapper my_wrap.exe -ggdb -o sign.exe sign.c


clean: 
	del *.exe *.o *.d *.asm *.sym

release: sign.exe
	copy sign.exe ..\

#	gcc $(CFLAGS) -nostdlib -ggdb -static -o sign.exe sign.c
