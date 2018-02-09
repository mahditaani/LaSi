//C++ INCLUDES
#include <iostream>
#include <cstdlib>

//LaSi INCLUDES
#include "global.h"
#include "generate.h"
#include "analysis.h"

//ROOT INCLUDES
#include "TH1D.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TStyle.h"
#include "TLegend.h"
#include "WLS.h"


extern bool verbosity;

int main() {//Start of the main function.

    verbosity = false;
    int seed = 12345;

    initRan(seed); //Start the random number generator.
    if (verbosity) {std::cout<<"Random number seed: "<<seed<<std::endl;}


    int numToGen = 1000; //Number of muons to generate.
    if (verbosity) {std::cout<<"Generating "<<numToGen<<" muons."<<std::endl;}

    std::vector<Muon> muons = GenMuons(numToGen,0.5,1); //Generates muons (number of muons, lowest energy, highest energy) uniform energy distribution

    WLS wlsPlate(0.28);

/*
    TFile *f1 = new TFile("SimulationResults.root", "RECREATE");

    TCanvas *c1 = new TCanvas("Hits", "Hits");
    c1->SetLogy();

    TLegend *l1 = new TLegend(0.7, 0.6, 0.9, 0.9);
    gStyle->SetOptStat(kFALSE);
    l1->AddEntry(h1,"Hole 1", "l");
    l1->AddEntry(h2,"Hole 2", "l");
    l1->AddEntry(h3,"Hole 3", "l");
    l1->AddEntry(h4,"Hole 4", "l");
    l1->AddEntry(h5,"Hole 5", "l");
    l1->AddEntry(h6,"Hole 6", "l");
    l1->AddEntry(h7,"Hole 7", "l");


    h7->SetTitle("Photons detected at different PMT positions.");
    h7->GetXaxis()->SetTitle("Number of Photons Detected");
    h7->Draw("p");//Drawn first as it has the largest y axis value.

    h2->Draw("same");
    h3->Draw("same");
    h4->Draw("same");
    h5->Draw("same");
    h6->Draw("same");
    h1->Draw("same");
    l1->Draw("same");
    c1->Write();

    TCanvas *cx = new TCanvas("HitsX", "HitsX");
    hx->Draw("COLZ");
    cx->Write();

    TCanvas *cy = new TCanvas("HitsY", "HitsY");
    hy->Draw("COLZ");
    cy->Write();

    TCanvas *cz = new TCanvas("HitsZ", "HitsZ");
    hz->Draw("COLZ");
    cz->Write();
*/
    TFile *f = new TFile("Test.root", "RECREATE");
    SaveSettings(f,wlsPlate);
    SaveHits(f,wlsPlate,muons,"Hole1");
    ChooseHole(2);
    SaveHits(f,wlsPlate,muons,"Hole2");
    ChooseHole(3);
    SaveHits(f,wlsPlate,muons,"Hole3");
    ChooseHole(4);
    SaveHits(f,wlsPlate,muons,"Hole4");
    ChooseHole(5);
    SaveHits(f,wlsPlate,muons,"Hole5");

    f->Close();


    return 0;
}//End of the main function.