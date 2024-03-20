#!/bin/bash

# Download FeynHiggs-2.18.1 tarball
#wget http://wwwth.mpp.mpg.de/members/heinemey/feynhiggs/newversion/FeynHiggs-2.18.1.tar.gz --no-check-certificate

# Extract the tarball
tar xfvz FeynHiggs-2.18.1.tar.gz

# Change into the extracted directory
cd FeynHiggs-2.18.1

# Modify the configure script to include -fPIE flag
sed -i '/CFLAGS-/ s/-Wall/-Wall -fPIE/' configure

# Run the configure script
./configure

# Compile FeynHiggs
make

# Change into the example directory
#cd example

# Compile the demo.cc program
#gfortran demo.cc -I../build -L../build/ -lFH -lstdc++ -o demo.exe

echo "FeynHiggs setup completed! You can find the compiled demo in the 'example' directory."
