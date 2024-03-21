#!/bin/bash

mkdir hdecay

cd hdecay

wget http://tiger.web.psi.ch/hdecay/hdecay.tar.gz

tar xfvz hdecay.tar.gz 


make FC=gfortran-9

make clean
