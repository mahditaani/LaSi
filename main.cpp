#include <iostream>
#include "global.h"
#include "generate.h"

#include "TH1D.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TFile.h"

int main() {

    bool verbosity = true;
    int seed = 12345;

    initRan(seed); //Start the random number generator.
    if (verbosity) {std::cout<<"Random number seed: "<<seed<<std::endl;}

    int numToGen = 1000; //Number of muons to generate.
    if (verbosity) {std::cout<<"Generating "<<numToGen<<" muons."<<std::endl;}

    std::vector<Muon> muons = GenMuons(numToGen,0.5,1); //Generates muons (number of muons, lowest energy, highest energy) uniform energy distribution

    TFile *f1 = new TFile("SimulationResults.root", "RECREATE");

    //TH2D *h1 = new TH2D ("Number of Hits", "Number of Hits", 20, -1, 1, 1-, 0, 1);
    TH1D *h1 = new TH1D ("H1", "H1", 100,0, 100);

    for (int i = 0; i<numToGen;i++){
        int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);
        std::cout << "Number of hits: " << hits << std::endl;
        if (verbosity && i % 100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h1->Fill(hits);


    }//End of for loop

    TH1D *h2 = new TH1D ("H2", "H2", 100,0, 100);
    pmtPos[0] = pmtPos[0] - 0.04;
    std::cout <<pmtPos[0]<<std::endl;
    for (int i = 0; i<numToGen;i++){
        int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);

        if (verbosity && i % 100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h2->Fill(hits);


    }//End of for loop
    TH1D *h3 = new TH1D ("H3", "H3", 100,0, 100);
    pmtPos[0] = pmtPos[0] - 0.04;
    for (int i = 0; i<numToGen;i++){
        int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);

        if (verbosity &&i % 100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h3->Fill(hits);


    }//End of for loop
    TH1D *h4 = new TH1D ("H4", "H4", 100,0, 100);
    pmtPos[0] = pmtPos[0] - 0.04;
    for (int i = 0; i<numToGen;i++){
        int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);

        if (verbosity && i % 100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h4->Fill(hits);


    }//End of for loop
    TH1D *h5 = new TH1D ("H5", "H5", 100,0, 100);
    pmtPos[0] = pmtPos[0] - 0.04;
    for (int i = 0; i<numToGen;i++){
        int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);

        if (verbosity && i % 100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h5->Fill(hits);


    }//End of for loop
    TH1D *h6 = new TH1D ("H6", "H6", 100,0, 100);
    pmtPos[0] = pmtPos[0] - 0.04;
    for (int i = 0; i<numToGen;i++){
        int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);

        if (verbosity && i % 100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h6->Fill(hits);


    }//End of for loop
    TH1D *h7 = new TH1D ("H7", "H7", 100,0, 100);
    pmtPos[0] = pmtPos[0] - 0.04;
    for (int i = 0; i<numToGen;i++){
        int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);

        if (verbosity && i % 100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h7->Fill(hits);


    }//End of for loop


















/*    TFile *f1 = new TFile("SimulationResults.root", "RECREATE");

    TH2D *h1 = new TH2D ("Number of Hits", "Number of Hits", 20, -1, 0,100 , 0, 100);
    //TH1D *h1 = new TH1D ("H1", "H1", 100,0, 100);
    std::cout<< muons[0].GetVtx(0) << " "<< muons[0].GetVtx(1) << " "<< muons[0].GetVtx(2) << std::endl;
    for (int i = 0; i<20;i++){
        // int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);
        int hits = PhotonsDetected(muons[0], pmtPos, withWLS, pmtDiameter);

        if (verbosity && i % 100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h1->Fill(pmtPos[0],hits);
        pmtPos[0] = pmtPos[0] - 0.05;


    }//End of for loop
*/
    f1->Write();
    f1->Close();


    return 0;
}