2022/03/20

Windows�ƃR�}���h�v�����v�g��Unix-xv6���r���h������@
�F�씎�m

���e�t�H���_�[�̐���

Tools:
	�r���h�Ɏg�p���鎩��c�[����C�\�[�X�t�@�C���AMakefile���܂܂�Ă��܂��B
win_xv6:
	Windows�p�ɍ쐬���ꂽxv6�̃\�[�X�t�@�C�����܂܂�Ă��܂��B
xv6:
	xv6���r���h�����ƃf�B���N�g���ł��Bxv6�̑S�\�[�X�t�@�C���������ɃR�s�[���܂��B

���K�v�ȃ\�t�g�E�F�A

1)xv6�̃\�[�X�R�[�h
https://github.com/mit-pdos/xv6-public
��LURL�̃y�[�W����xv6-public-master.zip���_�E�����[�h���܂��B
�_�E�����[�h����xv6�̑S�t�@�C�����A�f�B���N�g��xv6�ɃR�s�[���܂��B

2) MinGW
MinGW�̓����
https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/
��LURL�̃y�[�W����mingw-get-setup.exe���_�E�����[�h���܂��B
���́AC:\MinGW�ɃC���X�g�[�����܂����B

3) BusyBox
BusyBox�̓����
http://frippery.org/busybox/
��LURL�̃y�[�W����busybox.exe�܂���busybox64.exe���_�E�����[�h���܂��B32�r�b�gWindows�����g���̕���busybox.exe���_�E�����[�h���Ă��������B
�_�E�����[�h����busybox.exe��Tools�t�H���_�[�Ɉړ����܂��B

4) QEMU
QEMU�̓����
https://www.qemu.org/download/#windows
��LURL�̃y�[�W����32-bit�܂���64-bit Windows�p�̃C���X�g�[���[���_�E�����[�h���܂��B32�r�b�gWindows�����g���̕���32-bit�ł��_�E�����[�h���Ă��������B
����64-bit�ł�qemu-w64-setup-20210825.exe���_�E�����[�h���܂����B
���́AC:\Program Files\qemu�̃t�H���_�[�ɃC���X�g�[�����܂����B

�����ݒ�
���L�̗�̂悤�ɁA
MinGW\bin;
Tools\;
qemu;
��PATH�ɐݒ肵�܂��B

@echo off
echo Setting up environment for xv6 build...
set PATH=C:\MinGW\bin;%PATH%
set PATH=C:\Users\uno\Desktop\Min\Tools\;%PATH%
set PATH=C:\Program Files\qemu;%PATH%
cd /D C:\Users\uno\Desktop\Min\xv6

���r���h���@
1) �_�E�����[�h����xv6�̑S�t�@�C�����A�f�B���N�g��xv6�ɃR�s�[���܂��B

2) win_xv6�̑S�\�[�X�t�@�C�����A�f�B���N�g��xv6�ɏ㏑�����܂��B

3) xv6�̃f�B���N�g���ŁAL2W.bat �����s���܂��B
���̃o�b�`�R�}���h�́A�\�[�X�t�@�C����Windows�p�Ɏ����I�ɏC�����܂��B

4) Tools�̃f�B���N�g�����A�_�E�����[�h���܂��B
xv6�̃f�B���N�g���ŁAmktools.bat �����s���܂��B���̃o�b�`�R�}���h�́A
Tools�Ɋ܂܂��c�[���������I�ɍ쐬���܂��B

5) �r���h��Ƃ��܂��B
make
make qemu

���̂Q�̃R�}���h�ŁAxv6���N�����܂��B

���Q�l����

Windows�ƃR�}���h�v�����v�g��Unix-xv6���r���h������@
�F�씎�m

amazon�������ł��܂��B

�ȏ�

