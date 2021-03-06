#!/bin/sh
export PATH=$PATH:./
echo "Test 1, cc file"
mcp -s mcp.cc -t test1.cc -t test2.cpp
echo "Test 2, ascii file"
mcp -s ascii.txt -t test1.txt
echo "Test 3, executable file"
mcp -s binary -t bincopy
echo "================================================================================"
echo "Error 1, src file doesn't exist"
mcp -s notexist -t blah
echo "Error 2, target file already exists"
mcp -s ascii.txt -t test1.cc
echo "Error 3, target files have same name"
mcp -s ascii.txt -t samename.txt -t samename.txt
exit 0
