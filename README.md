# xv6-windows
How to build and run Unix-xv6 with Command Prompt on Windows

* Introduction

In 1975, Bell Labs released Unix Version 6 (also known as Sixth Edition Unix). It was widely used as an educational tool at universities such as the University of California, Berkeley. Unix-xv6 to be built this time is Unix Version 6 ported to multiprocessor x86 by ANSI C, and is still used as an educational tool at universities such as Massachusetts Institute of Technology.

"I have built and run xv6 with Command Prompt (cmd.exe) on Windows 10". That's what I've done. Not on Linux, nor Windows10 + WSL environment, nor Windwos10 + Cygwin or MSYS environment, I built it on Windows10 using Command Prompt.
Why did I dare to choose more difficult way? Looking back now, I feel as follows. Building on Linux is like flying from Osaka to Tokyo. I arrive at my destination in an hour. The build is completed, the goal is achieved, and that's it. There is no room to know about the famous and attractive places between Osaka and Tokyo. Building on Windows was like traveling on foot along the 53 Stations of the Tokaido. It took about 2 weeks. I touched various tools, encountered problems one after another, gained a little knowledge each time, felt like I was improving my skills, and was happy when the problems were solved. And finally when xv6 showed me its prompt, I was really impressed. And I was also attached to xv6, which eventually worked. For the past two weeks, I enjoyed like I was excited to read detective novels, and I was absorbed in adventure games. By taking a detour and building on Windows, I feel like I've successfully completed my great adventure.

Let me introduce a little about what kind of trip it was. On Linux, "Download the xv6 source file and run the make command." this is all we need to do to build xv6. Then, "Install QEMU and enter the command make qemu." This start xv6. On the other hand, when I ran the make command on Windows 10, I got a lot of errors. I had to investigate the cause of the errors and resolve them altogether. I solved the make command errors, C compile errors, and other command errors one by one. I'm not an expert in the program, so I didn't know much about it, and the progress was as slow as a turtle. For make command, I started from understanding what was written in Makefile. Specifically, in addition to how to write Makefile, I investigated the operation of tools such as gcc, ld, objcopy, dd, qemu, and gdb used in Makefile and the meaning of their options. As a matter of course, I also searched for and obtained the Windows 10 version of these tools. I actually entered the command described in Makefile into the command prompt, and while confirming that my understanding was correct from the output result, I went forward step by step.
One of the big problems was that "the specifications and behavior of the tools are different between the Linux version and the Windows version". Especially the difference of gcc (ld) was fatal. In UNIX and Linux, the ELF format (Executable and Linking Format) is used for object files and executable files. Since xv6 is UNIX, it is necessary to have the compiler output programs such as kernel and init in ELF format when building xv6. The Linux version of gcc (ld) outputs in ELF format by default. On the other hand, Windows uses the PE format (Potable Executable). Naturally, the Windows version of gcc (ld) outputs the program in PE format. The problem is that the Windows version of gcc couldn't output in ELF format no matter what options were specified. Now, I will explain in detail in the text how to solve this problem.

After a few days of struggle, the compilation was successful. The next challenge is debugging. Looking at the description of Makefile, xv6 itself runs on a PC emulator QEMU. And debugging seems to be done by getting this QEMU and the debugger gdb work together. I copied and pasted the description of Makefile and enter the command on Windows. However, QEMU and gdb do not work together. Once again, I searched the QEMU and gdb manuals to get a better understanding of the behavior and options. As a result of various experiments, I was finally able to run QEMU at one command prompt, run gdb at another command prompt, and connect them by telnet connection.

How the trip went is like this. By the process so far, it seems that I could come to Hamamatsu on the Tokaido. It was such a trip, but I'm glad I tried it. I'm really glad I walked to the end without giving up. If anyone wants to take on the challenge, I would like to support them with all my might. The record of my trip may be useful to someone. This book was born from this thought.

******************************

* Description of the folders

Tools:

	Contains the C source file and Makefile of the self-made tools used for the build.
win_xv6:

	Contains xv6 source files created for Windows.
xv6:

	The working directory for building xv6. Copy all xv6 source files here.


* Required software

1) xv6 source code

https://github.com/mit-pdos/xv6-public

Download xv6-public-master.zip from the above URL page.
Copy all the downloaded xv6 files to the directory xv6.

2) MinGW
Where to get MinGW

https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/

Download mingw-get-setup.exe from the above URL page.
I installed it in C: \MinGW.

3) BusyBox
Where to get BusyBox

http://frippery.org/busybox/

Download busybox.exe or busybox64.exe from the above URL page. If you are using 32-bit Windows, please download busybox.exe.
Move the downloaded busybox.exe to Tools folder.

4) QEMU
Where to get QEMU

https://www.qemu.org/download/#windows

Download the installer for 32-bit or 64-bit Windows from the URL page above. If you are using 32-bit Windows, please download the 32-bit version.
I downloaded the 64-bit version of qemu-w64-setup-20210825.exe.
I installed it in the folder C: \Program Files\qemu.

* Setting up

As in the example below

MinGW \ bin;

Tools \;

qemu;

are set in the PATH.

@echo off

echo Setting up environment for xv6 build...

set PATH=C:\MinGW\bin;%PATH%

set PATH=C:\Users\uno\Desktop\Min\Tools\;%PATH%

set PATH=C:\Program Files\qemu;%PATH%

cd /D C:\Users\uno\Desktop\Min\xv6


* Build method

1) Copy all the downloaded xv6 files to the directory xv6.

2) Overwrite the entire source files of win_xv6 in the directory xv6.

3) Run L2W.bat in the xv6 directory.

This batch command automatically modifies the source files for Windows.

4) Download the Tools directory.

Run mktools.bat in the xv6 directory.
This batch command automatically compiles the tools included in Tools.

5) Perform the build work.

make

make qemu

These two commands will start xv6.

* Reference materials

How to build and run Unix-xv6 with Command Prompt on Windows

Hiroshi Uno

You can get it from amazon.

Thank you
