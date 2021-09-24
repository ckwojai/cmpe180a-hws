#!/bin/sh
export PATH=$PATH:./
echo "Test 1...expects [8 8; 10 10]"
matrixproduct -m matrix1.txt -M matrix2.txt
matrixproduct -M matrix2.txt -m matrix1.txt
echo "Test 2...expects [5 27 -2 12; -1 6 0 6]"
matrixproduct -m matrix3.txt -M matrix4.txt
echo "Error 1...row mismatch"
matrixproduct -m test1.txt -M matrix2.txt
echo "Error 2...column mismatch"
matrixproduct -m test2.txt -M matrix2.txt
echo "Error 3...invalid row and column #"
matrixproduct -m test3.txt -M matrix2.txt
echo "Error 4...invalid row and column content"
matrixproduct -m test4.txt -M matrix2.txt
echo "Error 5...file doesn't exist"
matrixproduct -m sth.txt -M matrix2.txt
echo "Error 6...bad flag"
matrixproduct -r matrix1.txt -M matrix2.txt
exit 0
