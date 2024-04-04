#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TCanvas.h"



void muonhistograms() {


    TFile* inputFile = new TFile("muons.root", "READ");

    Double_t eta; //Pseudorapidity
    Double_t pT;  //Transverse momentum

    TTree* muonTree = dynamic_cast<TTree*> (inputFile -> Get("MuonTree"));

    muonTree -> SetBranchAddress("eta", &eta);
    muonTree -> SetBranchAddress("pT", &pT);

    TH1D* etaHist = new TH1D("etaHist", "Pseudorapidity Distribution", 50, -12.0, 12.0);
    TH1D* pTHist = new TH1D("pTHist", "Transverse momentum Distribution", 50, 0.0, 10.0);

//---------------------------------------------------------------------
// Filling the histograms:

    int entries = muonTree -> GetEntries();
    for (int i=0; i< entries; i++){
        muonTree  -> GetEntry(i);
        etaHist -> Fill(eta);
        pTHist -> Fill(pT);
    }


//--------------------------------------------------------------------
// Canvas for Pseudorapidity:

    TCanvas* c1 = new TCanvas("etaCanvas", "", 800, 600);

    //I just really love this fill colour. Hopefully it isn't too annoying, change to 0 from 42 if it is!
    c1 -> SetFillColor(42);

    etaHist -> SetLineColor(kBlack);
    etaHist -> SetLineWidth(3);
    etaHist -> SetFillColor(kYellow);
    etaHist -> GetXaxis() -> SetTitle("pseudorapidity");
    etaHist -> GetYaxis() -> SetTitle("Number of muons");

    etaHist -> Draw();

    c1 -> Print("Pseudorapidity_Distribution.pdf");
    c1 -> Print("Pseudorapidity_Distribution.root");


//-------------------------------------------------------------
// Canvas for Transverse momentum:

    TCanvas* c2 = new TCanvas("pTCanvas", "", 800, 600);

    c2 -> SetFillColor(42);

    pTHist -> SetLineColor(kBlack);
    pTHist -> SetLineWidth(2);
    pTHist -> SetFillColor(kYellow);
    pTHist -> GetXaxis() -> SetTitle("pT (GeV)");
    pTHist -> GetYaxis() -> SetTitle("Number of muons");
    pTHist -> Draw();

    c2 -> Print("Transverse_Momentum_Distribution.pdf");
    c2 -> Print("Transverse_Momentum_Distribution.root");



// Deleting stuff from memory
    delete etaHist;
    delete c1;
    delete pTHist;
    delete c2;
    


}
