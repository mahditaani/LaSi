//
// Created by mahdi on 29/01/18.
//

#include "analysis.h"
#include "generate.h"

extern double quartzThickness; //in m.
extern double quartzPos[3]; //in m.
extern double quartzDiameter; //in m.
extern double quartzAngle; //Angle of quartz plate in degrees.
extern double quartzRefractiveIndex;

extern double pmtPos[3];//in m. //THIS DEFINES THE CENTER OF THE GEOMETRY
extern double pmtDiameter; //in m.
extern double pmtRadius; //in m.


extern double wavelengthLow;
extern double wavelengthHigh;


void SaveSettings(TFile *f){


//    TGraph *pmtQE = new TGraph(n, x ,y); // This will display the QE as a scatter plot


    TTree * t = new TTree("Settings","Settings");

    t->Branch("QuartzThickness", &quartzThickness, "QuartzThickness/D");
    t->Branch("QuartzDiameter", &quartzDiameter, "QuartzDiameter/D");
    t->Branch("QuartzAngle", &quartzAngle, "QuartzAngle/D");
    t->Branch("QuartzRefractiveIndex", &quartzRefractiveIndex, "QuartzRefractiveIndex/D");
    t->Branch("QuartzPosX", &quartzPos[0], "QuartzPosX/D");
    t->Branch("QuartzPosY", &quartzPos[1], "QuartzPosY/D");
    t->Branch("QuartzPosZ", &quartzPos[2], "QuartzPosZ/D");

    t->Branch("PMTDiameter", &pmtDiameter, "PMTDiameter/D");
    t->Branch("PMTRadius", &pmtRadius, "PMTRadius/D");
    t->Branch("PMTPosX", &pmtPos[0], "PMTPosX/D");
    t->Branch("PMTPosY", &pmtPos[1], "PMTPosY/D");
    t->Branch("PMTPosZ", &pmtPos[2], "PMTPosZ/D");



    t->Branch("WavelengthLow", &wavelengthLow, "WaveLengthLow/D");
    t->Branch("WavelengthHigh", &wavelengthHigh, "WaveLengthHigh/D");

    f->cd();
    t->Write();
}

void SaveSettings(TFile *f, WLS _wls){

    float qe = _wls.GetQE();
    float wlsX = _wls.GetLength(0);
    float wlsY = _wls.GetLength(1);
    float wlsThick = _wls.GetThickness();
    float wlsRI = _wls.GetRefractiveIndex();


    TTree * t = new TTree("Settings","Settings");

    TGraph * wlsAbsorb = new TGraph(_wls.GetAbsorbSpectrum()[0][0],_wls.GetAbsorbSpectrum()[1],_wls.GetAbsorbSpectrum()[2]);
    wlsAbsorb->SetTitle("Absorption Spectra");
    wlsAbsorb->SetName("WLSAbsorptionSpectra");
    TGraph * wlsEmit = new TGraph(_wls.GetEmitSpectrum()[0][0],_wls.GetEmitSpectrum()[1],_wls.GetEmitSpectrum()[2]);
    wlsEmit->SetTitle("Emission Spectra");
    wlsEmit->SetName("WLSEmissionSpectra");



    t->Branch("QuartzThickness", &quartzThickness, "QuartzThickness/D");
    t->Branch("QuartzDiameter", &quartzDiameter, "QuartzDiameter/D");
    t->Branch("QuartzAngle", &quartzAngle, "QuartzAngle/D");
    t->Branch("QuartzRefractiveIndex", &quartzRefractiveIndex, "QuartzRefractiveIndex/D");
    t->Branch("QuartzPosX", &quartzPos[0], "QuartzPosX/D");
    t->Branch("QuartzPosY", &quartzPos[1], "QuartzPosY/D");
    t->Branch("QuartzPosZ", &quartzPos[2], "QuartzPosZ/D");

    t->Branch("PMTDiameter", &pmtDiameter, "PMTDiameter/D");
    t->Branch("PMTRadius", &pmtRadius, "PMTRadius/D");
    t->Branch("PMTPosX", &pmtPos[0], "PMTPosX/D");
    t->Branch("PMTPosY", &pmtPos[1], "PMTPosY/D");
    t->Branch("PMTPosZ", &pmtPos[2], "PMTPosZ/D");

    t->Branch("WavelengthLow", &wavelengthLow, "WaveLengthLow/D");
    t->Branch("WavelengthHigh", &wavelengthHigh, "WaveLengthHigh/D");

    t->Branch("WLSQE", &qe, "WLSQE/F");
    t->Branch("WLSRefractiveIndex", &wlsRI, "WLSRefractiveIndex/F");
    t->Branch("WLSLengthX",&wlsX, "WLSLengthX/F");
    t->Branch("WLSLengthY",&wlsY, "WLSLengthY/F");
    t->Branch("WLSThickness",&wlsThick, "WLSThickness/F");
//    t->Branch("WLSAbsorptionSpectra", wlsAbsorb);
//    t->Branch("WLSEmissionSpectra", wlsEmit);


    f->cd();
    t->Fill();
    t->Write();
    wlsAbsorb->Write();
    wlsEmit->Write();
}



void SaveHits(TFile* f, WLS _wls, std::vector<Muon> _muon, std::string treeName ){

    f->cd();

    TTree * t = new TTree(treeName.c_str(),treeName.c_str());
    int numHitsWLS = 0;
    int numHitsPMT = 0;
    int numPhots = 0;

    t->Branch("WLSHits",&numHitsWLS, "WLSHits/I");
    t->Branch("PMTHits",&numHitsPMT, "PMTHits/I");
    t->Branch("NumPhots",&numPhots, "NumPhots/I");



    for (int j = 0; j < _muon.size(); j++) {

        numHitsWLS = 0;
        numHitsPMT = 0;
        auto a = BasicLab(_muon[j],_wls);
        numPhots = a.size();
//        std::cout << "Number of detected phots: " << a.size() << std::endl;
        for (int i = 0; i < a.size(); i++) {

            if (a[i].material == "WLS") {numHitsWLS++;}
            if (a[i].material == "PMT") {numHitsPMT++;}

//            std::cout << "wavelength: " << a[i].wavelength;
//            std::cout << ", material: " << a[i].material << std::endl;
        }

        t->Fill();

    }

    f->cd();
    t->Write();


}

