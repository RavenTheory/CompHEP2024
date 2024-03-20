#!/bin/bash


# Compile the demo.cc program
gfortran demo.cc -IFeynHiggs-2.18.1/build -LFeynHiggs-2.18.1/build/ -lFH -lstdc++ -o demo.exe
./demo.exe > feyndata.txt
echo "The program demo.exe has been executed and the data is in the file feyndata.txt"