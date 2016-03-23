#!/bin/bash

CURL_PKG=`find . Packages/ -type d -name CCurl*`

function Build(){
    cd $CURL_PKG
    cd curl
    ${PWD}/buildconf
    ${PWD}/configure --prefix="$PWD/../build"
    /usr/bin/make -j8  
}

function InstallLibrary() {
    make install
}

function CopyDynamicLibrary() {
    mkdir -p ${PWD}/../.build/debug
    mkdir -p ${PWD}/../.build/release
    
    cp $PWD/../build/lib/libcurl* ${PWD}/../../.build/debug
}

Build
InstallLibrary


#CopyDynamicLibrary
    
