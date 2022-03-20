# Makefile for building on Windows
# Modified by Hiroshi Uno

OBJS = \
	bio.o\
	console.o\
	exec.o\
	file.o\
	fs.o\
	ide.o\
	ioapic.o\
	kalloc.o\
	kbd.o\
	lapic.o\
	log.o\
	main.o\
	mp.o\
	picirq.o\
	pipe.o\
	proc.o\
	sleeplock.o\
	spinlock.o\
	string.o\
	swtch.o\
	syscall.o\
	sysfile.o\
	sysproc.o\
	trapasm.o\
	trap.o\
	uart.o\
	vectors.o\
	vm.o\

TOOLPREFIX = 
QEMU = qemu-system-i386

CC = $(TOOLPREFIX)gcc
AS = $(TOOLPREFIX)gas
LD = $(TOOLPREFIX)ld

OBJCOPY = $(TOOLPREFIX)objcopy
OBJDUMP = $(TOOLPREFIX)objdump

CFLAGS = -fno-pic -static -fno-builtin -fno-strict-aliasing -O2 -Wall -MD -ggdb -m32 -Werror -fno-omit-frame-pointer
CFLAGS += -fno-stack-protector
ASFLAGS = -m32 -gdwarf-2 -Wa,-divide
LDFLAGS +=

CFLAGS += -fno-pie -no-pie
CFLAGS += -fno-leading-underscore

DD = busybox dd
SED = busybox sed
GREP = busybox grep

xv6.img: bootblock kernel_elf
	$(DD) if=/dev/zero of=xv6.img count=10000
	$(DD) if=bootblock of=xv6.img conv=notrunc
	$(DD) if=kernel_elf of=xv6.img seek=1 conv=notrunc

xv6memfs.img: bootblock kernelmemfs
	dd if=/dev/zero of=xv6memfs.img count=10000
	dd if=bootblock of=xv6memfs.img conv=notrunc
	dd if=kernelmemfs of=xv6memfs.img seek=1 conv=notrunc

bootblock: bootasm.S bootmain.c
	$(CC) $(CFLAGS) -fno-pic -O -nostdinc -I. -c bootmain.c
	$(CC) $(CFLAGS) -fno-pic -nostdinc -I. -c bootasm.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0x7C00 -o bootblock.o bootasm.o bootmain.o
	$(OBJDUMP) -S bootblock.o > bootblock.asm
	$(OBJCOPY) -S -O binary -j .text bootblock.o bootblock
	sign bootblock

entryother_nb: entryother.S
	$(CC) $(CFLAGS) -fno-pic -nostdinc -I. -c entryother.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0x7000 -o bootblockother.o entryother.o
	$(OBJCOPY) -S -O binary -j .text bootblockother.o entryother
	$(OBJDUMP) -S bootblockother.o > entryother.asm
	$(OBJCOPY) -S -j .text bootblockother.o entryother_nb

initcode_nb: initcode.S
	$(CC) $(CFLAGS) -nostdinc -I. -c initcode.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0 -o initcode.out initcode.o
	$(OBJCOPY) -S -O binary initcode.out initcode
	$(OBJDUMP) -S initcode.o > initcode.asm
	$(OBJCOPY) -S initcode.out initcode_nb

kernel_elf: $(OBJS) entry.o entryother_nb initcode_nb kernel.ld
	$(LD) $(LDFLAGS) -T kernel.ld -o kernel entry.o $(OBJS) initcode_nb entryother_nb
	$(OBJDUMP) -S kernel > kernel.asm
	$(OBJDUMP) -t kernel | $(SED) "1,/SYMBOL TABLE/d; s/ .* / /; /^$$/d" > kernel.sym
	$(OBJCOPY) -O elf32-i386 kernel kernel_elf
	setpaddr kernel_elf > kernel_elf.set
	$(OBJDUMP) -S kernel_elf > kernel_elf.asm
	$(OBJDUMP) -t kernel_elf | $(SED) "1,/SYMBOL TABLE/d; s/ .* / /; /^$$/d" > kernel_elf.sym

vectors.S: vectors.pl
	vectors > vectors.S

ULIB = ulib.o usys.o printf.o umalloc.o

_%: %.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main1 -Ttext 0 -o $@.exe $^
	$(OBJCOPY) -S -O elf32-i386 $@.exe $@
	$(OBJDUMP) -S $@ > $*.asm
	$(OBJDUMP) -t $@ | $(SED) "1,/SYMBOL TABLE/d; s/ .* / /; /^$$/d" > $*.sym

_forktest: forktest.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o _forktest forktest.o ulib.o usys.o
	$(OBJDUMP) -S _forktest > forktest.asm

mkfs.exe: mkfs.c fs.h
	gcc -ggdb -Werror -Wall -o mkfs mkfs.c

.PRECIOUS: %.o

UPROGS=\
	_cat\
	_echo\
	_forktest\
	_grep\
	_init\
	_kill\
	_ln\
	_ls\
	_mkdir\
	_rm\
	_sh\
	_stressfs\
	_usertests\
	_wc\
	_zombie\

fs.img: mkfs.exe README $(UPROGS)
	./mkfs fs.img README $(UPROGS)

-include *.d

clean: 
	rm -f *.tex *.dvi *.idx *.aux *.log *.ind *.ilg \
	*.o *.d *.asm *.sym vectors.S bootblock entryother \
	initcode initcode.out kernel xv6.img fs.img kernelmemfs \
	xv6memfs.img mkfs .gdbinit \
	$(UPROGS)

ifndef CPUS
CPUS := 2
endif
QEMUOPTS = -drive file=fs.img,index=1,media=disk,format=raw -drive file=xv6.img,index=0,media=disk,format=raw -smp $(CPUS) -m 512 $(QEMUEXTRA)

qemu: fs.img xv6.img
	$(QEMU) -serial mon:stdio $(QEMUOPTS)

qemu-nox: fs.img xv6.img
	$(QEMU) -nographic $(QEMUOPTS)

