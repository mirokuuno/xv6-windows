March 20, 2022

How to build and run Unix-xv6 with Command Prompt on Windows
Hiroshi Uno

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

2)MinGW
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
iss set in the PATH.

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



