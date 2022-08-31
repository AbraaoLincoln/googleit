#!/bin/bash

gcc `pkg-config --cflags gtk+-3.0` -o ./releases/googleit main.c `pkg-config --libs gtk+-3.0`

echo "running the app..."

./releases/googleit