#!/bin/bash

printf "\n ====================================== Debugging Project... ===================================== \n\n"
cd build/bin/
gdb -ex run starter
