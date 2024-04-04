#Instructions on using the code: Compilation + execution + result

#For both problems:

make
make simulate
./simulate.job
root muonhistograms.cc
root probablityCalc.cc


#Problem 1 only:

make
make simulate
./simulate.job
root muonhistograms.cc


#Problem 2 only (requires data from problem 1):

root probablityCalc.cc


## Results of problem1:

Histograms for distribution of transverse momentum and pseudorapidity as both .pdf and .root files (2 graphs with 4 files).


##Result of problem2:

The output from running probablityCalc.cc was the following:

---------------------------------------------------------------------------------------------------------------------------
The probability that my muon system would detect a muon from a minimum bias event simulated in 1 is: 0.114965%
---------------------------------------------------------------------------------------------------------------------------

##Note:
I did also include the data file from simulation (muons.root) since it's small and didn't want to have make clean remove .root files.