//C++ INCLUDES
#include <iostream>

//LaSi INCLUDES
#include "global.h"
#include "generate.h"

//ROOT INCLUDES
#include "TH1D.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TStyle.h"
#include "TLegend.h"

int main() {//Start of the main function.

    bool verbosity = false;
    int seed = 12345;

    initRan(seed); //Start the random number generator.
    if (verbosity) {std::cout<<"Random number seed: "<<seed<<std::endl;}

    int numToGen = 1000; //Number of muons to generate.
    if (verbosity) {std::cout<<"Generating "<<numToGen<<" muons."<<std::endl;}

    std::vector<Muon> muons = GenMuons(numToGen,0.5,1); //Generates muons (number of muons, lowest energy, highest energy) uniform energy distribution
/*
    TFile *f1 = new TFile("SimulationResults.root", "RECREATE");

    TH2D *hx = new TH2D ("Number of Hits vs X", "Number of Hits vs X", 20, 0.0, 0.2, 8, 0, 40);
    hx->GetXaxis()->SetTitle("Muon X position [m]");
    hx->GetYaxis()->SetTitle("Number of Photons Detected");
    TH2D *hy = new TH2D ("Number of Hits vs Y", "Number of Hits vs Y", 20, -0.1, 0.1, 8, 0, 40);
    hy->GetXaxis()->SetTitle("Muon Y position [m]");
    hy->GetYaxis()->SetTitle("Number of Photons Detected");
    TH2D *hz = new TH2D ("Number of Hits vs Z", "Number of Hits vs Z", 20, 0.0, 0.2, 8, 0, 40);
    hz->GetXaxis()->SetTitle("Muon Z position [m]");
    hz->GetYaxis()->SetTitle("Number of Photons Detected");

//-----------------BEGIN FOR HOLE 1---------------------------------------------------------------------------------
    TH1D *h1 = new TH1D ("H1", "H1", 40,0, 40);
    h1->SetStats(false);
    h1->SetLineColor(1);
    h1->SetLineWidth(5);

    for (int i = 0; i<numToGen;i++){
        int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);
        std::cout << "Number of hits: " << hits << std::endl;
        if (verbosity && i % 100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h1->Fill(hits);
        hx->Fill(muons[i].GetVtx(0),hits);
        hy->Fill(muons[i].GetVtx(1),hits);
        hz->Fill(muons[i].GetVtx(2),hits);

    }//End of for loop
//-----------------END OF HOLE 1------------------------------------------------------------------------------------


//-----------------BEGIN FOR HOLE 2---------------------------------------------------------------------------------
    TH1D *h2 = new TH1D ("H2", "H2", 40,0, 40);
    h2->SetStats(false);
    h2->SetLineColor(2);
    h2->SetLineWidth(5);
    pmtPos[0] = pmtPos[0] - 0.04;
    std::cout <<pmtPos[0]<<std::endl;
    for (int i = 0; i<numToGen;i++){
        int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);

        if (verbosity && i % 100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h2->Fill(hits);


    }//End of for loop
//-----------------END OF HOLE 2------------------------------------------------------------------------------------

//-----------------BEGIN FOR HOLE 3---------------------------------------------------------------------------------
    TH1D *h3 = new TH1D ("H3", "H3", 40,0, 40);
    h3->SetStats(false);
    h3->SetLineColor(46);
    h3->SetLineWidth(5);
    pmtPos[0] = pmtPos[0] - 0.04;
    for (int i = 0; i<numToGen;i++){
        int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);

        if (verbosity &&i % 100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h3->Fill(hits);


    }//End of for loop
//-----------------END OF HOLE 3------------------------------------------------------------------------------------


//-----------------BEGIN FOR HOLE 4---------------------------------------------------------------------------------
    TH1D *h4 = new TH1D ("H4", "H4", 40,0, 40);
    h4->SetStats(false);
    h4->SetLineColor(4);
    h4->SetLineWidth(5);
    pmtPos[0] = pmtPos[0] - 0.04;
    for (int i = 0; i<numToGen;i++){
        int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);

        if (verbosity && i % 100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h4->Fill(hits);


    }//End of for loop
//-----------------END OF HOLE 4------------------------------------------------------------------------------------



//-----------------BEGIN FOR HOLE 5---------------------------------------------------------------------------------
    TH1D *h5 = new TH1D ("H5", "H5", 40,0, 40);
    h5->SetStats(false);
    h5->SetLineColor(28);
    h5->SetLineWidth(5);
    pmtPos[0] = pmtPos[0] - 0.04;
    for (int i = 0; i<numToGen;i++){
        int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);

        if (verbosity && i % 100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h5->Fill(hits);


    }//End of for loop
//-----------------END OF HOLE 5------------------------------------------------------------------------------------




//-----------------BEGIN FOR HOLE 6---------------------------------------------------------------------------------
    TH1D *h6 = new TH1D ("H6", "H6", 40,0, 40);
    h6->SetStats(false);
    h6->SetLineColor(6);
    h6->SetLineWidth(5);
    pmtPos[0] = pmtPos[0] - 0.04;
    for (int i = 0; i<numToGen;i++){
        int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);

        if (verbosity && i % 100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h6->Fill(hits);


    }//End of for loop
//-----------------END OF HOLE 6------------------------------------------------------------------------------------




//-----------------BEGIN FOR HOLE 7---------------------------------------------------------------------------------
    TH1D *h7 = new TH1D ("H7", "H7", 40,0, 40);
    h7->SetStats(false);
    h7->SetLineColor(12);
    h7->SetLineWidth(5);
    pmtPos[0] = pmtPos[0] - 0.04;
    for (int i = 0; i<numToGen;i++){
        int hits = PhotonsDetected(muons[i], pmtPos, withWLS, pmtDiameter);

        if (verbosity && i % 100 == 0) {std::cout <<"Processing number "<<i <<std::endl; }

        h7->Fill(hits);


    }//End of for loop
//-----------------END OF HOLE 7------------------------------------------------------------------------------------



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

    f1->Write();
    f1->Close();
*/
/*
    for (int i = 0; i < numToGen; i++){

        photonJourney(muons[i]);
    }
  */
    //for (int j = 0; j < numToGen; j++) {
    for (int j = 0; j < 1; j++) {

        auto a = photonJourney(muons[j]);
        std::cout << "Number of detected phots: " << a.size() << std::endl;
        for (int i = 0; i < a.size(); i++) {

            std::cout << "wavelength: " << a[i].wavelength;
            std::cout << ", material: " << a[i].material << std::endl;
        }
    }
    return 0;
}//End of the main function.