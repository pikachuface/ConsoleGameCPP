#!/bin/bash

project=ConsoleGameCPP

builddir=Build
scrdir=ConsoleGameCPP


mkdir ${builddir}
cd ${builddir}

cmake -G "Unix Makefiles" ../ 

cd ../

cmake --build -S ${scrdir} -B ${builddir}
