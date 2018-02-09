//
// Created by mahdi on 29/01/18.
//

#ifndef LASI_ANALYSIS_H
#define LASI_ANALYSIS_H


#include <TFile.h>
#include <TTree.h>
#include <TGraph.h>
#include <TH1F.h>

#include "WLS.h"
#include "muon.h"

void SaveSettings(TFile* f);
void SaveSettings(TFile* f, WLS _wls);

void SaveHits(TFile* f, WLS _wls, std::vector<Muon> _muon, std::string treeName );





#endif //LASI_ANALYSIS_H
