import ROOT
import ctypes


def p1():
    # First we create an output file
    outputFile = ROOT.TFile("random_numbers.root", "RECREATE")

    # Tree
    nums = ROOT.TTree("nums", "Tree to store randomly generated numbers that are normally distributed")


    randomnum = ctypes.c_double(0.0)
    addr_randomnum = ctypes.addressof(randomnum)
    nums.Branch("randomnum", addr_randomnum , "randomnum/D")

    # Now we initiate random number generator
    randgenerator = ROOT.TRandom3()

    N = 1000
    for i in range(N):
        randomnum = ctypes.c_double(randgenerator.Gaus(0, 1))
        #print(randomnum)
        # has mean of 0 and sigma of 1S
        nums.Fill()
        
    nums.Write()

    # Close the output file
    outputFile.Close()

    print(f"{N} normally distributed random numbers have been generated and saved into a root file called random_numbers.root.")

# Call the function
p1()
