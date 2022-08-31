#!/bin/bash

echo "📚 Generating resources..."

glib-compile-resources ./src/resources/googleitapp.gresource.xml --target=./src/c/resources.c --generate-source

echo "🖥  Compiling the application.."

gcc $(pkg-config --cflags gtk+-3.0) -o ./releases/googleit ./src/c/*.c $(pkg-config --libs gtk+-3.0)


if [ $? -eq 0 ]; then
    echo "🏃 Running the app..."
    ./releases/googleit
fi