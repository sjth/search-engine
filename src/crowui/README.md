# Instructions

## Building pre-requisites

  Run one of the build commands below: I ran the second one:
  
    sudo apt-get install build-essential libtcmalloc-minimal4 && sudo ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so
    
    sudo apt-get install build-essential libtcmalloc-minimal0 && sudo ln -s /usr/lib/libtcmalloc_minimal.so.0 /usr/lib/libtcmalloc_minimal.so

## Compiling

  Run the following command:
  
    make -j$(($(grep -c '^processor' /proc/cpuinfo)+1))

## Running

  Run the newly created executable.

## Understanding the code

  Other than framework dependencies, everything else needed to serve the pages is within search\_srv.cpp
