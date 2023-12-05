#!/bin/bash

for file in **/*.cpp; do
    dir=$(dirname "$file")
    filename=$(basename "$file" .cpp)
    target="$dir/$filename"
    if [ -f "$target" ]; then
        echo "rm $target"
        rm "$target"
    fi
done