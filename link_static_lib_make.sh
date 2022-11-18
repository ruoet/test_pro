#!/bin/bash
echo "link static lib make main!"
g++ -g main.cpp -lmymath -Lsrc -Iinclude -o static_main
