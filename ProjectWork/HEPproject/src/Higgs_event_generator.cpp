
#include "Pythia8/Pythia.h"
#include "TTree.h"
#include "TFile.h"
using namespace std;
using namespace Pythia8;

int find_final_children(Event event, int parent_index, int daughter_indices[2]) {
    Particle parent = event[parent_index];
    Particle daughter1 = event[parent.daughter1()];
    if (daughter1.id() != parent.id()) {
        daughter_indices[0] = parent.daughter1();
        daughter_indices[1] = parent.daughter2();
        return daughter1.id();
    } else {
        return find_final_children(event, parent.daughter1(), daughter_indices);
    }
}

int find_final_index(Event event, int parent_index) {
    Particle parent = event[parent_index];
    if (parent.status() > 0) {
        return parent_index;
    }
    if (event[parent.daughter1()].id() == parent.id()) {
        if (event[parent.daughter1()].status() > 0) {
            return parent.daughter1();
        } else {
            return find_final_index(event, parent.daughter1());
        }
    }
    if (event[parent.daughter2()].id() == parent.id()) {
        if (event[parent.daughter2()].status() > 0) {
            return parent.daughter2();
        } else {
            return find_final_index(event, parent.daughter2());
        }
    }
    return -1;
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

    const float Higgs_mass = 125;
    const int Higgs_id = 25;
    const int muon_id = 13;
    const int event_count = stoi(settings["Higgs_event_generator_event_count"]);

    TFile out_file("Higgs_muon_decays.root","RECREATE");

    TTree metadata("metadata", "Additional information");

    int total_events = event_count;
    metadata.Branch("total_events", &total_events, "total_events/I");
    int muon_events = 0;
    metadata.Branch("muon_events", &muon_events, "muon_events/I");

    TTree muons("muons", "Higgs muon decays");

    vector<float> px;
    vector<float> py;
    vector<float> pz;
    vector<float> e;
    vector<float> m;
    vector<int> Q;
    vector<int> H;

    muons.Branch("px", "vector<float>", &px);
    muons.Branch("py", "vector<float>", &py);
    muons.Branch("pz", "vector<float>", &pz);
    muons.Branch("e", "vector<float>", &e);
    muons.Branch("m", "vector<float>", &m);
    muons.Branch("Q", "vector<int>", &Q);
    muons.Branch("H", "vector<int>", &H);

    Pythia pythia;
    pythia.readString("25:m0 = " + to_string(Higgs_mass));
    pythia.readString("HiggsSM:all = on");
    pythia.readString("Beams:eCM = 13600.");

    //setting random seed:
    pythia.readString("Random:setSeed = on");
    pythia.readString("Random:seed = 0"); //This 0 means that a different seed is chosen based on time!
    //-------------------------------------------

    pythia.init();

    for (int iEvent = 0; iEvent < event_count; ++iEvent) {
        pythia.next();

        bool muon_decay = false;
        int Higgs_daughter_indices[2];
        for (int i=0; i<pythia.event.size(); ++i) {
            if (pythia.event[i].id() == Higgs_id) {
                int daughter_id = find_final_children(pythia.event, i, Higgs_daughter_indices);
                //cout << daughter_id << ", " << daughter_indices[0] << ", " << daughter_indices[1] << endl;
                if (daughter_id == muon_id) {
                    muon_decay = true;
                    ++muon_events;
                    Higgs_daughter_indices[0] = find_final_index(pythia.event, Higgs_daughter_indices[0]);
                    Higgs_daughter_indices[1] = find_final_index(pythia.event, Higgs_daughter_indices[1]);
                    //if (Higgs_daughter_indices[0] == -1 || Higgs_daughter_indices[1] == -1) {
                    //    pythia.event.list(false, true);
                    //}
                }
                break;
            }
        }
        if (!muon_decay) {
            continue;
        }
        int higgs_muons = 0;
        vector<int> muon_indices;
        for (int i=0; i<pythia.event.size(); ++i) {
            if (pythia.event[i].status() < 0) {
                continue;
            }
            if (pythia.event[i].id() == muon_id || pythia.event[i].id() == -1*muon_id) {
                Particle muon = pythia.event[i];
                px.push_back(muon.px());
                py.push_back(muon.py());
                pz.push_back(muon.pz());
                e.push_back(muon.e());
                m.push_back(muon.m());
                if (pythia.event[i].id() == muon_id) {
                    Q.push_back(-1);
                } else {
                    Q.push_back(1);
                }
                if (i == Higgs_daughter_indices[0] || i == Higgs_daughter_indices[1]) {
                    H.push_back(1);
                    higgs_muons++;
                    muon_indices.push_back(i);
                    muon_indices.push_back(1);
                } else {
                    H.push_back(0);
                    muon_indices.push_back(i);
                    muon_indices.push_back(0);
                }
            }
        }

        muons.Fill();
        px.clear();
        py.clear();
        pz.clear();
        e.clear();
        m.clear();
        Q.clear();
        H.clear();
    }

    pythia.stat();

    cout << "Muon decays: " << muon_events <<endl;

    metadata.Fill();
    metadata.Write();
    muons.Write();
    out_file.Close();

    cout << "\"Higgs_muon_decays.root\" successfully written." << endl;

}