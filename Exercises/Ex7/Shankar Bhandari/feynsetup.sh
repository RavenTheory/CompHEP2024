#!/bin/bash

# Download FeynHiggs-2.18.1 tarball
wget http://wwwth.mpp.mpg.de/members/heinemey/feynhiggs/newversion/FeynHiggs-2.18.1.tar.gz --no-check-certificate

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


echo "FeynHiggs setup completed!"
