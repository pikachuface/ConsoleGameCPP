@echo off
echo Making your VS solution...

pushd ../

set builddir=Build
set rootdir=%cd%

md %builddir%

pushd %builddir%
Cmake -G "Visual Studio 16 2019" %rootdir%
