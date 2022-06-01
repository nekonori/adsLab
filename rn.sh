#!/bin/bash

file=$1
if [ ! -f "$file" ]; then
	echo "File not found"
	exit 1
fi

g++ $file && ./a.out
