# Instructions on usage

Remember to give permission to .sh files.
The hdecaySetup.sh should've been made as a makefile but realised it too late to fix it now.

## Problem 1: running the program

hdecaySetup.sh
pyroot hdecay.py



## Problem 2:

hdecaySetup.sh (Only if not already done)
pyroot FeynHiggs


# Some explanations

## The code for Problem 1 is in hdecay.py and in the script hdecaySetup.sh
hdecay.py calculates the width for different higgs masses and makes a plot using ROOT. 
The output of this file is Hiss_width_as_function_of_mass_hdecay.pdf and Hiss_width_as_function_of_mass_hdecay.ROOT.

This can be run with "pyroot hdecay.py" and it should work as long as there is hdecay program inside the directory hdecay with the executable named run that one gets from using the makefile.
The hdecay program can be installed by using the bash script hdecaySetup.sh. It will download the decay and then compile to get the makefile.



## The code for problem 2 is in FeynHiggs_Hdecay.py, demo.cc and two scripts feynsetup.sh and runFeynHiggs.sh

For this program it is enough to just run the python program FeynHiggs_Hdecay, unless you haven't configured hdecay yet since it is used by FeynHiggs_Hdecay.py
NOTE THAT THE BASH SCRIPTS REQUITE PERMISSION TO EXECUTE!

feynsetup.sh is a bash script that downloads and build the FeynHiggs program from the tar file for the programm.
And the python program actually calls this script if necessary so user doesn't have to worry about that.

runFeynHiggs.sh is a bash script that runs the compiling and executing the resulting file. 
This also directs the output of the executable into a txt file called feyndata.txt for our python program to read.

demo.cc is the file using FeynHiggs that gets compiled and run as demo.exe which then prints the results.
This demo.cc is copy of the example file provided along with the FeynHiggs program, with a small modification that allows for calculating the total width of the SM Higgs.

Finally the FeynHiggs_Hdecay.py is the program that combines all of the scripts and programs mentioned above to give us the graphs using ROOT.
This program also needs the hdecay.py since it uses it as a module and then calls its functions.
The output file of this program are HdecayVsFeynHiggs.pdf and HdecayVsFeynHiggs.ROOT.


