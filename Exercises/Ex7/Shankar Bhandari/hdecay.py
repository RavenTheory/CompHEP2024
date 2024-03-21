
import numpy as np
import subprocess
import os
import sys
from ROOT import TCanvas, TGraph, TFile
from array import array

def setup():
    
    if os.path.isdir("hdecay"):
        print("The folder hdecay exists!!")
    else:
        
        #For whatever reason this didn't work (tried also with changing the makefile inside hdecay with python to give it gfortran-9 as compiler)
        #subprocess.run( './hdecaySetup.sh' )
        #Not enough time to fix it to the level I wan't so this shall do
        print("Please run the hdecaySetup.sh script using following command: ./hdecaySetup.sh")
        print("Just like for other .sh scripts it might be necessary to give necessary permissions for this script to execute!!")
        sys.exit()       

def updateHiggsMass(mHiggs):
    #This function modifies the mass parameter for SM Higgs in the input file for HDECAY executable
    filename = "hdecay/hdecay.in"
    try:
        with open(filename, 'r' ) as f:
            lines = f.readlines()

        for i, line in enumerate(lines):
            if "MABEG" in line:
                lines[i] = (f"MABEG    = {mHiggs}D0\n")
                break
        
        with open(filename, 'w') as f:
            f.writelines(lines)
        
        #print("File updated succesfully")
    except FileNotFoundError:
        print(f"{filename} not found.")

def calculateWidth(mHiggs):
    #This function runs the executable called run, if there is no such file it first uses the make command to make it
    
    #First we update the mass of the higgs using the function we defined above

    updateHiggsMass(mHiggs)
    
    os.chdir("hdecay")
    
    if os.path.isfile("run"):
        subprocess.run(["./run"])
    else:
        raise FileNotFoundError("ERROR: 'run' file not  found. Go to the hdcay file and run 'make' in the terminal to get the executable so that this program can run")

    os.chdir("..")
 
def getWidth():
    #This reads then gives the width from the file br.sm2
    filename = "hdecay/br.sm2"
    
    try:
        with open(filename, 'r') as f:
            lines = f.readlines()
        #The file is formatted such that the data is always in the 4th line and the width is in the last column
        #The data is seperated by 1 or more space
        
        data = lines[3].split()
        width = data[-1]
        
        return float(width)
    
    except FileNotFoundError:
        print(f"{filename} not found.")

def main():
    
    setup()

    #Let's first print the value of width with the Higgs mass of 125:
    
    calculateWidth(125.0)
    W = getWidth()
    
    print(f"The SM Higgs boson width for m_H = 125 GeV is {W}")
    
    #The canvas drawing adapted from PyRoot tutorials
    
    c1 = TCanvas( 'c1', 'Higgs Width', 200, 10, 700, 500 )
 
    c1.SetFillColor( 42 )
    c1.SetGrid()
    
    
    n = 30 #The number of mass parameters
    mHiggs, width = array( 'd' ), array( 'd' )
    
    #Creating the mass range to check the Higgs mass
    for i in range( n ):
        mHiggs.append( 15.2 * i + 50.4)
        
    
    for i, m in enumerate(mHiggs):
        try:
            calculateWidth(m)
        except FileNotFoundError as e:
            print(e)
         
        w = getWidth()
        width.append(w)
        
        #print(w) #incase one wants to see every result printed



    gr = TGraph( n, mHiggs, width )
    gr.SetLineColor( 2 )
    gr.SetLineWidth( 4 )
    gr.SetMarkerColor( 4 )
    gr.SetMarkerStyle( 21 )
    gr.SetTitle( 'Higgs Width' )
    gr.GetXaxis().SetTitle( 'Mass (GeV) ' )
    gr.GetYaxis().SetTitle( 'Width (GeV)' )
    gr.GetYaxis().SetRangeUser(-1, max(width)+4)  # Range for Y axis
    gr.Draw( 'ACP' )
    
    #Saving the graph in ROOT file:
    output_file = TFile("Higgs_width_as_function_of_mass_hdecay.root", "RECREATE")
    c1.Write()
    output_file.Close()
    
    #Saving as a pdf
    c1.SaveAs("Higgs_width_as_function_of_mass_hdecay.pdf")
    
    # TCanvas.Update() draws the frame, after which one can change it
    c1.Update()
    c1.GetFrame().SetFillColor( 21 )
    c1.GetFrame().SetBorderSize( 12 )
    c1.Modified()
    c1.Update()
    c1.WaitPrimitive()
    del c1


if __name__ == "__main__":
    main()
