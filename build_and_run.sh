#!/bin/bash

./build_app.sh

if [ $? -eq 0 ]; then
    echo "🏃 Running the app..."
    ./releases/googleit
fi