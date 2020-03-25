
echo Making gcc make files....
pushd ../

set builddir=Build
set rootdir=%cd%

md %builddir%

pushd %builddir%
cmake -G "MinGW Makefiles" %rootdir%
echo 
cmake --build . --config Debug
echo Building your app.....
pause
