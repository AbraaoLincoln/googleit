#!/bin/bash

echo "📚 Generating resources..."

glib-compile-resources googleitapp.gresource.xml --target=resources.c --generate-source

echo "🖥  Compiling the application..."

gcc $(pkg-config --cflags gtk+-3.0) -o ./releases/googleit *.c $(pkg-config --libs gtk+-3.0)
