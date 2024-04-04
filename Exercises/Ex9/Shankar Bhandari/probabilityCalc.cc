#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TCanvas.h"



//This is the code for problem 2.
//This reads the output root file from the simulation 
//and calculates the probability of detecting a muon with certain transverse momentum and pseudorapidity.


void probabilityCalc(){


    TFile* inputFile = new TFile("muons.root", "READ");

    Double_t eta; //Pseudorapidity
    Double_t pT;  //Transverse momentum

    TTree* muonTree = dynamic_cast<TTree*> (inputFile -> Get("MuonTree"));

    muonTree -> SetBranchAddress("eta", &eta);
    muonTree -> SetBranchAddress("pT", &pT);

    int detectedMuonCount = 0;

    int muonCount = muonTree -> GetEntries();
    for (int i=0; i< muonCount; i++){
        muonTree  -> GetEntry(i);
        if ( pT>5.0 && abs(eta) < 2.5){
            detectedMuonCount++;
        }
    }    

    double prob_detect;

    //THe amount of muons detected is very very low so better to have it in terms of percentage (multiplying by 100)
    prob_detect = static_cast<double>(detectedMuonCount)/muonCount * 100;

    //cout << "Amount of muons detected: " << detectedMuonCount << endl;
    //cout << "Total amount of muons produced: " << muonCount << endl;

    cout << "---------------------------------------------------------------------------------------------------------------------------" << endl; 
    cout << "The probability that my muon system would detect a muon from a minimum bias event simulated in 1 is: " << prob_detect << "%" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------" << endl; 

}