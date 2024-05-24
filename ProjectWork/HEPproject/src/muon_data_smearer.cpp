
#include <iostream>
#include <fstream>
#include "TTree.h"
#include "TFile.h"
#include "TTreeReader.h"
#include "TTreeReaderArray.h"
#include "TRandom3.h"
#include <string>

using namespace std;

float calculate_p(float px, float py, float pz) {
    return sqrt(px*px + py*py + pz*pz);
}

float calculate_theta(float p, float pz){
    return acos(pz/p);
}

float calculate_eta(float theta) {
    return -log(tan(theta/2));
}

float calculate_eta(float px, float py, float pz) {
    return atanh(pz/calculate_p(px, py, pz));
}

float calculate_phi(float px, float py) {
    return atan2(py, px);
}

float calculate_pT(float p, float eta) {
    return p/cosh(eta);
}

void read_settings(map<string, string>& settings) {
    string line;
    ifstream ReadFile("settings.txt");
    while (getline (ReadFile, line)) {
        if (line[0] == '#') { //skip line if it's commented
            continue;
        }
        string variable = "";
        string value = "";
        bool variable_name_area = true;
        for (int i=0; i<line.length(); i++) {
            if (line[i] == ' ' || line[i] == '\n') {
                continue;
            }
            if (line[i] == '=') {
                variable_name_area = false;
                continue;
            }
            if (variable_name_area) {
                variable += line[i];
            } else {
                value += line[i];
            }
        }
        settings[variable] = value;
    }
}

int main() {

    map<string, string> settings;
    read_settings(settings);
    TString filename = settings["muon_data_smearer_filename"];

    //Creating objects for old data

    TFile in_file(filename + ".root");

    TTree* old_metadata;
    in_file.GetObject("metadata", old_metadata);

    int total_events;
    old_metadata->SetBranchAddress("total_events", &total_events);
    int muon_events;
    old_metadata->SetBranchAddress("muon_events", &muon_events);

    old_metadata->GetEntry(0);


    TTreeReader Reader("muons",&in_file);

    TTreeReaderArray<float> old_px(Reader, "px");
    TTreeReaderArray<float> old_py(Reader, "py");
    TTreeReaderArray<float> old_pz(Reader, "pz");
    TTreeReaderArray<float> old_e(Reader, "e");
    TTreeReaderArray<float> old_m(Reader, "m");
    TTreeReaderArray<int> old_Q(Reader, "Q");
    TTreeReaderArray<int> old_H(Reader, "H");


    //Creating objects for new data

    TFile out_file(filename + "_smeared.root","RECREATE");

    TTree new_metadata("metadata", "Additional information");

    new_metadata.Branch("total_events", &total_events, "total_events/I");
    new_metadata.Branch("muon_events", &muon_events, "muon_events/I");

    new_metadata.Fill();


    TTree new_muons("muons", "Higgs muon decays with smearing");

    vector<float> new_p;
    vector<float> new_pT;
    vector<float> new_eta;
    vector<float> new_phi;
    vector<float> new_m;
    vector<int> new_Q;
    vector<int> new_H;

    new_muons.Branch("p", "vector<float>", &new_p);
    new_muons.Branch("pT", "vector<float>", &new_pT);
    new_muons.Branch("eta", "vector<float>", &new_eta);
    new_muons.Branch("phi", "vector<float>", &new_phi);
    new_muons.Branch("m", "vector<float>", &new_m);
    new_muons.Branch("Q", "vector<int>", &new_Q);
    new_muons.Branch("H", "vector<int>", &new_H);

    TRandom3* rndm = new TRandom3();
    rndm->SetSeed(); //Gives a random seed each time program is run

    while (Reader.Next()) {
        for (int i=0;i<old_px.GetSize();i++) {

            float old_p = calculate_p(old_px[i], old_py[i], old_pz[i]);
            float old_theta = calculate_theta(old_p, old_pz[i]);
            float old_phi = calculate_phi(old_px[i], old_py[i]);

            new_p.push_back(old_p*rndm->Gaus(1, 0.01));

            float new_theta = old_theta + rndm->Gaus(0, 0.002);
            new_eta.push_back(calculate_eta(new_theta));

            new_phi.push_back(old_phi + rndm->Gaus(0, 0.002));

            new_pT.push_back(calculate_pT(new_p.back(), new_eta.back()));
            new_m.push_back(old_m[i]);
            new_Q.push_back(old_Q[i]);
            new_H.push_back(old_H[i]);
            
        }

        new_muons.Fill();
        new_p.clear();
        new_pT.clear();
        new_eta.clear();
        new_phi.clear();
        new_m.clear();
        new_Q.clear();
        new_H.clear();

    }

    new_metadata.Write();
    new_muons.Write();
    out_file.Close();

    cout << "\"" + filename + "_smeared.root\" successfully written." << endl;

}