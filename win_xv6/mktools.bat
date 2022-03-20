rem Batch command to make tools that are used to build kernel on Windows
rem by Hiroshi Uno
rem 

for %%i in (setpaddr sign vectors wrapper) do (
cd ../Tools
cd %%i
make
make release
cd ../../xv6
)
