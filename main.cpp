#include <iostream>
#include "global.h"
#include "generate.h"

#include "TH1D.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TFile.h"

int main() {


    initRan(12345); //Start the random number generator.

    int numToGen = 1000; //Number of muons to generate.

    std::vector<Muon> muons = GenMuons(numToGen,0.5,1); //Generates muons (number of muons, lowest energy, highest energy) uniform energy distribution

    TFile *f1 = new TFile("SimulationResults.root", "RECREATE");

    //TH2D *h1 = new TH2D ("Number of Hits", "Number of Hits", 20, -1, 1, 1-, 0, 1);
    TH1D *h1 = new TH1D ("Number of Hits", "Number of Hits", 100,0, 100);

    for (int i = 0; i<numToGen;i++){
        int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);

        if (numToGen%100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h1->Fill(hits);


    }//End of for loop


    TCanvas *c1 = new TCanvas();
    h1->Draw();
    f1->Write();
    f1->Close();


    return 0;
}