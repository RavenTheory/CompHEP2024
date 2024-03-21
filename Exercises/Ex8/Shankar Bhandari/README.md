# Istructions on using the code: Compilation + execution + result

## For both problems

make
make both
jobScript.job



## Problem 1 only

make
make p1
p1.job


## Compile for problem 2 only

make
make simulateEvents
p2.job


## Result of problem 1:
Here is what the program printed when running program for problem 1:

--------------------------------------------------------------------------

The width of the Higgs boson with mass 125 GeV is: 0.004 GeV

--------------------------------------------------------------------------

## The BW-width that I got in my run for problem 2:

--------------------------------------------------------------------------

The (Breit-Wigner) width calculated from the plot is: 0.00389393 GeV

--------------------------------------------------------------------------

## Some notes:
The make and job files are adapted form the example 2 of the Lecture 9
For some reason the Pythia ./configure didn't work for me in this directory but worked perfectly fine on other directories.
So when using it I first configured pythia in other directory and copied to this one for my use.
The distribution plot is included as a pdf but the data is not.