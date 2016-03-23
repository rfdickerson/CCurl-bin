#!/bin/bash

function Build(){
    cd curl
    ./buildconf
    ./configure --prefix="$PWD/../build"
    make -j8  
}

function InstallLibrary() {
    cd curl
    make install
}

function CopyDynamicLibrary() {
    mkdir -p ${PWD}/../.build/debug
    mkdir -p ${PWD}/../.build/release
    
    cp $PWD/../build/lib/libcurl* ${PWD}/../../.build/debug
}

BuildConf
InstallLibrary
CopyDynamicLibrary
    
