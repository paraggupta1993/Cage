#!/usr/bin/bash

#g++ a.cpp  `gtk-config --cflags --libs` && ./a.out 

#g++ -L/usr/lib64  -lgtk -lgdk -rdynamic -lgmodule -ldl -lglib -lXi -lXext -lX11 -lm  -I/usr/include/gtk-2.0 -I/usr/lib64/gtk-2.0/include -I/usr/include/pango-1.0/ -I/usr/include/cairo/ -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -I/usr/include/gdk-pixbuf-2.0/ -I/usr/include/atk-1.0/ a.cpp

#g++ -L/usr/lib64  -lgtk -lgdk -rdynamic -lgmodule -ldl -lglib -lXi -lXext -lX11 -lm  -I/usr/include/gtk-2.0 -I/usr/lib64/gtk-2.0/include -I/usr/include/pango-1.0/ -I/usr/include/cairo/ -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -I/usr/include/gdk-pixbuf-2.0/ -I/usr/include/atk-1.0/ a.cpp
#g++ a.cpp `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0` 
g++ $1 `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` `pkg-config --libs webkitgtk-3.0` `pkg-config --cflags webkitgtk-3.0` && ./a.out
 
