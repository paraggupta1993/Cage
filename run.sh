#!/usr/bin/bash

#compiling and run if successful 
g++ $1 `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` `pkg-config --libs webkitgtk-3.0` `pkg-config --cflags webkitgtk-3.0` && ./a.out
 
