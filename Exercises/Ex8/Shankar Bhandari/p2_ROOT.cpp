#include <fstream>
#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TF1.h"
//#include "TTree"

void p2_ROOT() {

    std::ifstream in("data.txt", std::ios_base::in);
    std::string line;

    TTree* data = new TTree("data", "Tree to store the miggs mass from the event generator");
    
    TCanvas* canvas1 = new TCanvas("mycanva", "cc1", 800, 600);
    canvas1 -> SetFillColor(0);

    TH1F* higgsMass = new TH1F("Higgs Mass", "Higgs Mass", 30, 124.98, 125.03);


    double m_higgs;
    data -> Branch("M_Higgs", &m_higgs, "mhiggs/D");

    while (std::getline(in, line)) {
        m_higgs = std::stod(line);

        data -> Fill();        
    }

    int entries = data -> GetEntries();
    for (int i=0; i<entries; i++){
        data -> GetEntry(i);
        higgsMass -> Fill(m_higgs);
    }


    
    // Fitting a Breit-Wigner function to the histogram:
    TF1* bw = new TF1("bw", "[0]*TMath::BreitWigner(x, [1], [2])", 124.98, 125.03);
    bw->SetParameters(5, 125.03, 40);  // Initial parameters
    higgsMass->Fit(bw, "R");
    

    higgsMass->Draw();
    canvas1 -> SaveAs("HiggsMassDistribution.pdf");


    std::cout << "--------------------------------------------------------------------------" << std::endl << std::endl;
    std::cout << "The (Breit-Wigner) width calculated from the plot is: " << bw->GetParameter(2) << " GeV" << std::endl << std::endl;
    std::cout << "--------------------------------------------------------------------------" << std::endl << std::endl;


    in.close();
}
