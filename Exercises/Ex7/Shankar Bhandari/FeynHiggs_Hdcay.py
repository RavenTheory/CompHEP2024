
import numpy as np
import subprocess
import os
import ctypes
from ROOT import TCanvas, TGraph, TFile, TLegend
from array import array
import hdecay


#This starts with the assumption that there will be at least the tar folder in the directory of this program
#since the tar folder will be uploaded in the github along with other files. Then this setup part will setup the
# FeynHiggs using a bash sccript. Permission must be given to the bash script to execute for this setup to work.
def setup():
    
    if os.path.isdir("FeynHiggs-2.18.1"):
        print("The file FeynHiggs-2.18.1 exists, there is no need for futher setup")
    else:
        subprocess.run( './feynsetup.sh' )
 
    
def updateHiggsMass(mHiggs):
    #This function updates the mass by updating the parametr MA0 in the demo.cc file
    filename = "demo.cc"
    
    try: 
        with open(filename, 'r') as f:
            lines = f.readlines()
        for i, line in enumerate(lines):
            if "cRealType MA0" in line:
                lines[i] = (f"cRealType MA0 = {mHiggs};\n")
                break
                
        with open(filename, 'w') as f:
            f.writelines(lines)
            

    except FileNotFoundError:
        print(f"{filename} not found")


#def runHigs():
    #subprocess.run( './runFeynHiggs.sh' )

#I have figured out that it is much more powerful to write a bash script and execute it from python than to try scripting from python at least for this use case, so I am doing exactly that
#Also the exact command line arguments that worked in runFeynHiggs.sh didn't work with subprocess, so I just decided to use the bash script
def calculateWidth(mHiggs):
    #This file first updates the mass of the Higgs and then executes the program that calculates the width
    updateHiggsMass(mHiggs)
    #runHigs()
    subprocess.run( './runFeynHiggs.sh' )
    #This will print the data to an output file named feyndata.txt


def getWidth():
    #This function reads the data that is the output from running the demo.exe program
    filename = 'feyndata.txt' 
    
    try:
        with open(filename, 'r') as f:
            lines = f.readlines()
        
        for i, line in enumerate(lines):
            if "Gamma =" in line:
                width = line.split("=")[-1]
                return float(width)
            
            
    except FileNotFoundError:
        print(f"{filename} not found.")


def main():
    
    print("Remember to give the permission to the bash scripts (ending in .sh) permission to execute")

    updateHiggsMass(140)
    
    setup()

    #runHigs()
    
    #calculateWidth(150)
    
    #print(getWidth())
    
    
    #This main is adapted from the problem 1
    #We are also using the python file of the program 1 as a module to call it's functions to use HDECAY

#------------------------------------------------------------------------------------------------------------    
    #The canvas drawing adapted from PyRoot tutorials
    
    c1 = TCanvas( 'c1', 'A Simple Graph Example', 200, 10, 700, 1000 )
    c1.Divide(1, 2)
    c1.cd(1)
 
    c1.SetFillColor( 42 )
    c1.SetGrid()
    
#------------------------------------------------------------------------------------------------------------
    n = 20 #The number of mass parameters
    mHiggs, width, width_hdecay = array( 'd' ), array( 'd' ), array('d')
    
    #Creating the mass range to check the Higgs mass
    for i in range( n ):
        mHiggs.append( 10.2 * i + 10.4)
        
    #we calculate widths in this loop for for HdECACY and FeynHiggs cases:
    for i, m in enumerate(mHiggs):
        try:
            calculateWidth(m)
        except FileNotFoundError as e:
            print(e)
        
        try: 
            hdecay.calculateWidth(m)
        except FileNotFoundError as e:
            print(e)
        
        w = getWidth()
        w_hdecacy = hdecay.getWidth()
        
        width.append(w)
        width_hdecay.append(w_hdecacy)
        
        #print(w) #incase one wants to see every result printed


#------------------------------------------------------------------------------------------------------------
    gr = TGraph( n, mHiggs, width )
    gr.SetLineColor( 2 )
    gr.SetLineWidth( 3 )
    gr.SetMarkerColor( 4 )
    gr.SetMarkerStyle( 21 )
    gr.SetTitle( 'Width of Higgs using Hdecay and FeynHiggs' )
    gr.GetXaxis().SetTitle( 'Mass (GeV) ' )
    gr.GetYaxis().SetTitle( 'Width (GeV)' )
    #gr.GetYaxis().SetRangeUser(-1, max(width)+4)  # Range for Y axis
    gr.Draw( 'ACP' )
    
#------------------------------------------------------------------------------------------------------------
    gr2 = TGraph( n, mHiggs, width_hdecay)
    gr2.SetLineColor( 1 )
    gr2.SetLineWidth( 1 )
    gr2.Draw( 'C' )


    legendaarinen = TLegend(0.11, 0.77, 0.3, 0.9)
    legendaarinen.AddEntry(gr, "FeynHiggs" )
    legendaarinen.AddEntry(gr2, "HDECAY" )
    legendaarinen.Draw()



#------------------------------------------------------------------------------------------------------------


    # Calculate the ratio of the two widths
    ratio = array('d', [w_hdecacy / w for w, w_hdecacy in zip(width, width_hdecay)])

    # Create a TGraph or TH1D for the ratio
    c1.cd(2)
    
    gr_ratio = TGraph(n, mHiggs, ratio)
    gr_ratio.SetLineColor(4)
    gr_ratio.SetLineWidth(2)
    gr_ratio.SetMarkerColor(2)
    gr_ratio.SetMarkerStyle(20)
    gr_ratio.SetTitle('Ratio of Hdecay Width to FeynHiggs Width')
    gr_ratio.GetXaxis().SetTitle('Mass (GeV)')
    gr_ratio.GetYaxis().SetTitle('Ratio')

    gr_ratio.Draw('ACP')
#------------------------------------------------------------------------------------------------------------
    
    
    #Saving the graph in ROOT file:
    output_file = TFile("HdecayVsFeynHiggs.root", "RECREATE")
    c1.Write()
    output_file.Close()
    
    #Saving as a pdf
    c1.SaveAs("HdecayVsFeynHiggs.pdf")
#------------------------------------------------------------------------------------------------------------


    # TCanvas.Update() draws the frame, after which one can change it
    c1.Update()
    c1.GetFrame().SetFillColor( 21 )
    c1.GetFrame().SetBorderSize( 12 )
    c1.Modified()
    c1.Update()
    c1.WaitPrimitive()
    del c1
#------------------------------------------------------------------------------------------------------------

if __name__ == "__main__":
    main()
