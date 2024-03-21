#include "Pythia8/Pythia.h"

using namespace Pythia8;

int main() {

    Pythia pythia;
    
    // Ok the Higgs mass default value in particle data table is also 125 GeV
    // and so we could maybe just read from that, but here is a method to do this by changing the mass.
    pythia.readString("25:m0 = 125.0");

    // Without initializing with init it would just give width of 0, so this is necessary:
    pythia.init();

    // Particle data for the Higgs boson:
    ParticleDataEntryPtr higgs = pythia.particleData.particleDataEntryPtr(25);

    // Higgs width:
    double higgsWidth = higgs->resWidth(25, 125.0, 0, false, false);
    cout << "--------------------------------------------------------------------------" << endl << endl;
    cout << "The width of the Higgs boson with mass 125 GeV is: " << higgsWidth << " GeV" << endl << endl;
    cout << "--------------------------------------------------------------------------" << endl << endl;
    return 0;
}
