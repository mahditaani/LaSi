//
// Created by mahdi on 09/02/18.
//

#include <cstdlib>
#include <iostream>

#include "TFile.h"
#include "TTree.h"
#include "TH1I.h"
#include "TCanvas.h"
#include "TLegend.h"

void MakePlots(const char *inFileName = "../Simulation.root", const char * outFileName = "Output.root"){


    gStyle->SetOptStat(kFALSE);


    TFile *f = new TFile(inFileName, "READ");

    TH1I *h1w = new TH1I("h1wls","Hole1 WLS Hits",150,0,149);
    TH1I *h2w = new TH1I("h2wls","Hole2 WLS Hits",150,0,149);
    TH1I *h3w = new TH1I("h3wls","Hole3 WLS Hits",150,0,149);
    TH1I *h4w = new TH1I("h4wls","Hole4 WLS Hits",150,0,149);
    TH1I *h5w = new TH1I("h5wls","Hole5 WLS Hits",150,0,149);
    TH1I *h1p = new TH1I("h1pmt","Hole1 PMT Hits",150,0,149);
    TH1I *h2p = new TH1I("h2pmt","Hole2 PMT Hits",150,0,149);
    TH1I *h3p = new TH1I("h3pmt","Hole3 PMT Hits",150,0,149);
    TH1I *h4p = new TH1I("h4pmt","Hole4 PMT Hits",150,0,149);
    TH1I *h5p = new TH1I("h5pmt","Hole5 PMT Hits",150,0,149);

    TTree *t1 = (TTree*)f->Get("Hole1");
    TTree *t2 = (TTree*)f->Get("Hole2");
    TTree *t3 = (TTree*)f->Get("Hole3");
    TTree *t4 = (TTree*)f->Get("Hole4");
    TTree *t5 = (TTree*)f->Get("Hole5");

    int wls1, wls2, wls3, wls4, wls5;
    int pmt1, pmt2, pmt3, pmt4, pmt5;

    t1->SetBranchAddress("WLSHits", &wls1);
    t1->SetBranchAddress("PMTHits", &pmt1);

    t2->SetBranchAddress("WLSHits", &wls2);
    t2->SetBranchAddress("PMTHits", &pmt2);

    t3->SetBranchAddress("WLSHits", &wls3);
    t3->SetBranchAddress("PMTHits", &pmt3);

    t4->SetBranchAddress("WLSHits", &wls4);
    t4->SetBranchAddress("PMTHits", &pmt4);

    t5->SetBranchAddress("WLSHits", &wls5);
    t5->SetBranchAddress("PMTHits", &pmt5);



    for (auto i = 0; i < t1->GetEntries(); i++){
        t1->GetEntry(i);
        t2->GetEntry(i);
        t3->GetEntry(i);
        t4->GetEntry(i);
        t5->GetEntry(i);

        h1p->Fill(pmt1);
        h1w->Fill(wls1);

        h2p->Fill(pmt2);
        h2w->Fill(wls2);

        h3p->Fill(pmt3);
        h3w->Fill(wls3);

        h4p->Fill(pmt4);
        h4w->Fill(wls4);

        h5p->Fill(pmt5);
        h5w->Fill(wls5);

    }






    TFile *of = new TFile(outFileName, "RECREATE");

    TCanvas *c1 = new TCanvas("PMTWLSHits1", "PMTWLSHits1");
    TCanvas *c2 = new TCanvas("PMTWLSHits2", "PMTWLSHits2");
    TCanvas *c3 = new TCanvas("PMTWLSHits3", "PMTWLSHits3");
    TCanvas *c4 = new TCanvas("PMTWLSHits4", "PMTWLSHits4");
    TCanvas *c5 = new TCanvas("PMTWLSHits5", "PMTWLSHits5");

    TCanvas *c6 = new TCanvas("PMTHits", "PMTHits");
    TCanvas *c7 = new TCanvas("WLSHits", "WLSHits");

    TLegend *l1 = new TLegend(0.7, 0.6, 0.9, 0.9);
    TLegend *l2 = new TLegend(0.7, 0.6, 0.9, 0.9);
    TLegend *l3 = new TLegend(0.7, 0.6, 0.9, 0.9);
    TLegend *l4 = new TLegend(0.7, 0.6, 0.9, 0.9);
    TLegend *l5 = new TLegend(0.7, 0.6, 0.9, 0.9);
    TLegend *l6 = new TLegend(0.7, 0.6, 0.9, 0.9);
    TLegend *l7 = new TLegend(0.7, 0.6, 0.9, 0.9);


//    c1->SetLogy();

    l1->AddEntry(h1p,"PMT Hits", "l");
    l1->AddEntry(h1w,"WLS Hits", "l");
    l2->AddEntry(h2p,"PMT Hits", "l");
    l2->AddEntry(h2w,"WLS Hits", "l");
    l3->AddEntry(h3p,"PMT Hits", "l");
    l3->AddEntry(h3w,"WLS Hits", "l");
    l4->AddEntry(h4p,"PMT Hits", "l");
    l4->AddEntry(h4w,"WLS Hits", "l");
    l5->AddEntry(h5p,"PMT Hits", "l");
    l5->AddEntry(h5w,"WLS Hits", "l");

    l6->AddEntry(h1p,"Hole 1", "l");
    l6->AddEntry(h2p,"Hole 2", "l");
    l6->AddEntry(h3p,"Hole 3", "l");
    l6->AddEntry(h4p,"Hole 4", "l");
    l6->AddEntry(h5p,"Hole 5", "l");

    l7->AddEntry(h1w,"Hole 1", "l");
    l7->AddEntry(h2w,"Hole 2", "l");
    l7->AddEntry(h3w,"Hole 3", "l");
    l7->AddEntry(h4w,"Hole 4", "l");
    l7->AddEntry(h5w,"Hole 5", "l");


    c1->cd();
    h1p->Draw("p");
    h1w->Draw("same");
    h1p->SetLineWidth(2);
    h1p->SetLineColor(kRed);
    h1w->SetLineWidth(2);
    h1w->SetLineColor(kBlue);
    l1->Draw("same");

    c2->cd();
    h2p->Draw("p");
    h2w->Draw("same");
    h2p->SetLineWidth(2);
    h2p->SetLineColor(kRed);
    h2w->SetLineWidth(2);
    h2w->SetLineColor(kBlue);
    l2->Draw("same");

    c3->cd();
    h3p->Draw("p");
    h3w->Draw("same");
    h3p->SetLineWidth(2);
    h3p->SetLineColor(kRed);
    h3w->SetLineWidth(2);
    h3w->SetLineColor(kBlue);
    l3->Draw("same");

    c4->cd();
    h4p->Draw("p");
    h4w->Draw("same");
    h4p->SetLineWidth(2);
    h4p->SetLineColor(kRed);
    h4w->SetLineWidth(2);
    h4w->SetLineColor(kBlue);
    l4->Draw("same");

    c5->cd();
    h5p->Draw("p");
    h5w->Draw("same");
    h5p->SetLineWidth(2);
    h5p->SetLineColor(kRed);
    h5w->SetLineWidth(2);
    h5w->SetLineColor(kBlue);
    l5->Draw("same");


    c6->cd();
    h1p->Draw();
    h2p->Draw("same");
    h3p->Draw("same");
    h4p->Draw("same");
    h5p->Draw("same");
    h1p->SetLineColor(kRed);
    h2p->SetLineColor(kBlue);
    h3p->SetLineColor(kYellow);
    h4p->SetLineColor(kBlack);
    h5p->SetLineColor(kMagenta);
    l6->Draw("same");

    c7->cd();
    h1w->Draw();
    h2w->Draw("same");
    h3w->Draw("same");
    h4w->Draw("same");
    h5w->Draw("same");
    h1w->SetLineColor(kRed);
    h2w->SetLineColor(kBlue);
    h3w->SetLineColor(kYellow);
    h4w->SetLineColor(kBlack);
    h5w->SetLineColor(kMagenta);
    l7->Draw("same");

/*
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
*/








    of->cd();

    h1w->Write();
    h1p->Write();
    h2w->Write();
    h2p->Write();
    h3w->Write();
    h3p->Write();
    h4w->Write();
    h4p->Write();
    h5w->Write();
    h5p->Write();
    c1->Write();
    c2->Write();
    c3->Write();
    c4->Write();
    c5->Write();
    c6->Write();
    c7->Write();

    of->Close();








}