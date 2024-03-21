// main02.cc is a part of the PYTHIA event generator.
// Copyright (C) 2016 Torbjorn Sjostrand.
// PYTHIA is licenced under the GNU GPL version 2, see COPYING for details.
// Please respect the MCnet Guidelines, see GUIDELINES for details.

// Adapted from main02.cc example program to simulate 1000 SM Higs


#include "Pythia8/Pythia.h"
using namespace Pythia8;
int main() {
  // Generator. Process selection. Tevatron initialization. Histogram.
  Pythia pythia;

  pythia.readString("Beams:eCM = 13000.");

  pythia.readString("HiggsSM:all = on");

  pythia.readString("Next:numberShowEvent=0");

  pythia.readString("PDF:pSet=8");                     // This built in PDF Is actually CTEQ6L1
  // Had some error with getting the example 3 of Lect 9 examples working so decided to go with this default one



  pythia.init();
  // Begin event loop. Generate event. Skip if error. List first one.
  for (int iEvent = 0; iEvent < 1000; ++iEvent) {
    if (!pythia.next()) continue;

    // Loop over particles in event. Find h0 and print it's mass.

    for (int i = 0; i < pythia.event.size(); ++i){
      if (pythia.event[i].id() == 25) cout <<  pythia.event[i].m() << endl;
      }

  }

  return 0;
}
                                         