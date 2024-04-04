#include "Pythia8/Pythia.h"
#include "TFile.h"
#include "TTree.h"



using namespace Pythia8;

int main() {

  // NUMBER OF EVENTS:
  int eventsN = 1000000;



  // Generator. Process selection.
  Pythia pythia;

  //Default is LHC collision at 14TeV of CM-energy so only changing the CM-energy away from default
  pythia.readString("Beams:eCM = 13600.");

  // Enabling the weak boson and qcd procecsses 
  pythia.readString("WeakBosonAndParton:ffbar2gmZgm = on");
  pythia.readString("HardQCD:all = on");

  pythia.readString("Next:numberShowEvent = 0");

  //pythia.readString("PDF:pSet=8");       //Ill just use default pdf and leave this one commented

  //LEt's create a rootfile to store the simulated data:
  TFile* outputFile = new TFile("muons.root", "RECREATE");
  TTree* muonTree = new TTree("MuonTree", "Muon Data");

  Double_t eta; //Pseudorapidity
  Double_t pT;  //Transverse momentum

  muonTree -> Branch("eta", &eta, "eta/D");
  muonTree -> Branch("pT", &pT, "pT/D");


  pythia.init();

  // Begin event loop. Generate event. Skip if error. List first one.
  for (int iEvent = 0; iEvent < eventsN; ++iEvent) {
    if (!pythia.next()) continue;

    // Loop over particles in event. Find h0 and print it's mass.
    for (int i = 0; i < pythia.event.size(); ++i){
      if (pythia.event[i].id() == 13){
        eta = pythia.event[i].eta();
        pT = pythia.event[i].pT();

        muonTree -> Fill();
        //cout <<  pythia.event[i].pT() << ";" << pythia.event[i].eta() << endl;
      }
      }
  }

  muonTree -> Write();
  outputFile -> Close();

  return 0;
}
                                         