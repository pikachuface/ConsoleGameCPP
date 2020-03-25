#!/bin/bash

project=ConsoleGameCPP

builddir=Build

pushd ../
rootdir=$PWD

mkdir -p ${builddir}
pushd ${builddir}

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ${rootdir}  

popd

cmake --build ${builddir} --config Debug --target all
