#!/bin/bash
echo "static library make!"
g++ -g mymath.cpp -c -I../include -std=c++11
ar rs libmymath.a mymath.o
