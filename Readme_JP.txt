2022/03/20

WindowsとコマンドプロンプトでUnix-xv6をビルドする方法
宇野博士

●各フォルダーの説明

Tools:
	ビルドに使用する自作ツールのCソースファイル、Makefileが含まれています。
win_xv6:
	Windows用に作成されたxv6のソースファイルが含まれています。
xv6:
	xv6をビルドする作業ディレクトリです。xv6の全ソースファイルをここにコピーします。

●必要なソフトウェア

1)xv6のソースコード
https://github.com/mit-pdos/xv6-public
上記URLのページからxv6-public-master.zipをダウンロードします。
ダウンロードしたxv6の全ファイルを、ディレクトリxv6にコピーします。

2) MinGW
MinGWの入手先
https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/
上記URLのページからmingw-get-setup.exeをダウンロードします。
私は、C:\MinGWにインストールしました。

3) BusyBox
BusyBoxの入手先
http://frippery.org/busybox/
上記URLのページからbusybox.exeまたはbusybox64.exeをダウンロードします。32ビットWindowsをお使いの方はbusybox.exeをダウンロードしてください。
ダウンロードしたbusybox.exeをToolsフォルダーに移動します。

4) QEMU
QEMUの入手先
https://www.qemu.org/download/#windows
上記URLのページから32-bitまたは64-bit Windows用のインストーラーをダウンロードします。32ビットWindowsをお使いの方は32-bit版をダウンロードしてください。
私は64-bit版のqemu-w64-setup-20210825.exeをダウンロードしました。
私は、C:\Program Files\qemuのフォルダーにインストールしました。

●環境設定
下記の例のように、
MinGW\bin;
Tools\;
qemu;
をPATHに設定します。

@echo off
echo Setting up environment for xv6 build...
set PATH=C:\MinGW\bin;%PATH%
set PATH=C:\Users\uno\Desktop\Min\Tools\;%PATH%
set PATH=C:\Program Files\qemu;%PATH%
cd /D C:\Users\uno\Desktop\Min\xv6

●ビルド方法
1) ダウンロードしたxv6の全ファイルを、ディレクトリxv6にコピーします。

2) win_xv6の全ソースファイルを、ディレクトリxv6に上書きします。

3) xv6のディレクトリで、L2W.bat を実行します。
このバッチコマンドは、ソースファイルをWindows用に自動的に修正します。

4) Toolsのディレクトリを、ダウンロードします。
xv6のディレクトリで、mktools.bat を実行します。このバッチコマンドは、
Toolsに含まれるツールを自動的に作成します。

5) ビルド作業します。
make
make qemu

この２つのコマンドで、xv6が起動します。

●参考資料

WindowsとコマンドプロンプトでUnix-xv6をビルドする方法
宇野博士

amazonから入手できます。

以上

