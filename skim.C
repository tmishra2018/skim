#include <iostream>
#include "TROOT.h"
#include "TH1.h"
#include <vector>
#include "TBranch.h"
#include <stdio.h>
#include "TString.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TBenchmark.h"
#include "TSystem.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TFile.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;
                                                //Dictionary for defining TLorentzVector
/*
#ifdef __CLING__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ class std::vector<TLorentzVector>+;
#endif
*/

void skim( const char *inputfile, const char *outputfile ){
	


   //  TFile *f = new TFile("Run2017F-31Mar2018-v1.SinglePhoton_391_RA2AnalysisTree.root");                                                                //Input root file 
   TFile *f;
   //f = new TFile(inputfile,"READ","",4);
   f = TFile::Open(inputfile);

   TTree *t1 =(TTree*)f->Get("/TreeMaker2/PreSelection");
   cout<<"\nTotal Entries in input file : "<< t1->GetEntries()<<"\n";
 
   UInt_t RunNum,LumiBlockNum;
   ULong64_t EvtNum;
   Bool_t BadChargedCandidateFilter,BadPFMuonFilter,hasGenPromptPhoton,JetID,JetIDAK8,JetIDAK8Clean,JetIDclean;
   
   Int_t NJets,NVtx,nAllVertices, isoElectronTracks,isoMuonTracks,isoPionTracks,BTags,NElectrons,NJetsclean,NMuons,BTagsclean,BTagsDeepCSV,BTagsDeepCSVclean,CSCTightHaloFilter,ecalBadCalibFilter,EcalDeadCellTriggerPrimitiveFilter,eeBadScFilter,globalTightHalo2016Filter,HBHEIsoNoiseFilter,HBHENoiseFilter,isoElectronTracksclean,isoMuonTracksclean,PrimaryVertexFilter,isoPionTracksclean; 
   
   Double_t MET,METclean,METcleanOrig,METOrig,METPhi,METPhiclean,METPhicleanOrig,METPhiOrig,METSignificance,METSignificanceclean,MHTcleanOrig,MHTOnline,MHTOrig,MHTPhiclean,MHTPhicleanOrig,MHTPhiOrig,MJJ_AK8, Mmc_AK8,MT_AK8,MHTPhi,CaloMETPhi,MHT,MHTclean,CaloMET,MT2,DeltaPhi1,DeltaPhi2,DeltaPhi3,DeltaPhi4,PrescaleWeightHT, PFCaloMETRatio,DeltaPhi1_AK8,DeltaPhi1clean,DeltaPhi1cleanOrig,DeltaPhi1Orig,DeltaPhi2_AK8,DeltaPhi2clean,DeltaPhi2cleanOrig,DeltaPhi2Orig,DeltaPhi3clean,DeltaPhi3cleanOrig,DeltaPhi3Orig,DeltaPhi4clean,DeltaPhi4cleanOrig,DeltaPhi4Orig,DeltaPhiMin_AK8,HT,HT5,HT5clean,HTclean,HTOnline;
   
   vector <int> *Jetsclean_hadronFlavor = 0,*Muons_charge = 0, *TAPElectronTracks_charge = 0,*TAPMuonTracks_charge = 0,*Electrons_charge = 0,*Jets_chargedHadronMultiplicity = 0,*Jets_chargedMultiplicity = 0,*JetsAK8Clean_NumBhadrons = 0,*JetsAK8Clean_NumChadrons,*Jets_electronMultiplicity,*Jets_hadronFlavor,*Jets_multiplicity,*Jets_muonMultiplicity,*Jets_neutralHadronMultiplicity,*Jets_neutralMultiplicity,*Jets_partonFlavor,*Jetsclean_partonFlavor,*Jets_photonMultiplicity,*JetsAK8_multiplicity,*JetsAK8_NumBhadrons,*JetsAK8_NumChadrons,*TAPPionTracks_charge,*TriggerPass,*TriggerPrescales,*TriggerVersion;
  
   vector<bool> *Electrons_mediumID,*Electrons_passIso,*Electrons_tightID,*Muons_passIso,*Muons_tightID,*Photons_electronFakes,*Photons_fullID,*Jets_HTMask,*Jets_ID,*Jets_LeptonMask,*Jets_MHTMask,*Jets_MHTOrigMask,*JetsAK8_ID,*Jetsclean_HTMask,*Jetsclean_ID,*Photons_nonPrompt,*Jetsclean_MHTMask,*Jetsclean_MHTOrigMask;
  
   vector<double> *Electrons_MiniIso,*Muons_MiniIso,*Muons_MT2Activity,*Muons_MTW,*Electrons_MT2Activity,*Electrons_MTW,*Jets_axismajor,*Jets_axisminor,*Jets_bDiscriminatorCSV,*Jets_bJetTagDeepCSVBvsAll,*Jets_bJetTagDeepCSVCvsB,*Jets_bJetTagDeepCSVCvsL,*Jets_bJetTagDeepCSVprobb,*Jets_bJetTagDeepCSVprobbb,*Jets_bJetTagDeepCSVprobc,*Jetsclean_muonEnergyFraction,*Jets_bJetTagDeepCSVprobudsg,*Jets_bJetTagDeepFlavourprobb,*Jets_bJetTagDeepFlavourprobbb,*Jets_bJetTagDeepFlavourprobc,*Jets_bJetTagDeepFlavourprobg,*Jets_bJetTagDeepFlavourproblepb,*Jets_bJetTagDeepFlavourprobuds,*Jets_chargedEmEnergyFraction,*Jets_chargedHadronEnergyFraction,*Jets_electronEnergyFraction,*Jets_hfEMEnergyFraction,*Jets_hfHadronEnergyFraction,*JetsAK8_overflow,*JetsAK8_prunedMass,*JetsAK8_ptD,*JetsAK8_ptdrlog,*JetsAK8_softDropMass,*Jets_jecFactor,*Jets_jecUnc,*Jets_muonEnergyFraction,*JetsAK8_tDiscriminatorDeep,*JetsAK8_tDiscriminatorDeepDecorrel,*JetsAK8Clean_prunedMass,*JetsAK8Clean_softDropMass,*Jetsclean_bDiscriminatorCSV,*Jetsclean_bJetTagDeepCSVBvsAll,*Jetsclean_bJetTagDeepCSVCvsB,*Jetsclean_bJetTagDeepCSVCvsL,*Jetsclean_bJetTagDeepCSVprobb,*Jetsclean_bJetTagDeepCSVprobbb,*Jetsclean_bJetTagDeepCSVprobc,*Jetsclean_bJetTagDeepCSVprobudsg,*Jetsclean_bJetTagDeepFlavourprobb,*Jetsclean_bJetTagDeepFlavourprobbb,*Jetsclean_bJetTagDeepFlavourprobc,*Jetsclean_bJetTagDeepFlavourprobg,*Jetsclean_bJetTagDeepFlavourproblepb,*Jetsclean_bJetTagDeepFlavourprobuds,*Jetsclean_chargedHadronEnergyFraction,*JetsAK8_wDiscriminatorDeep,*JetsAK8_wDiscriminatorDeepDecorrel,*JetsAK8_zDiscriminatorDeep,*JetsAK8_zDiscriminatorDeepDecorrel,*JetsAK8Clean_doubleBDiscriminator,*JetsAK8Clean_ecfN2b1,*JetsAK8Clean_ecfN2b2,*JetsAK8Clean_ecfN3b1,*JetsAK8Clean_ecfN3b2,*JetsAK8Clean_NsubjettinessTau1,*JetsAK8Clean_NsubjettinessTau2,*JetsAK8Clean_NsubjettinessTau3,*Jets_neutralEmEnergyFraction,*Jets_neutralHadronEnergyFraction,*Jets_photonEnergyFraction,*Jets_ptD,*Jets_qgLikelihood,*JetsAK8_axismajor,*JetsAK8_axisminor,*JetsAK8_doubleBDiscriminator,*JetsAK8_ecfN2b1, *JetsAK8_ecfN2b2,*JetsAK8_ecfN3b1,*JetsAK8_ecfN3b2,*JetsAK8_girth,*JetsAK8_hDiscriminatorDeep,*JetsAK8_hDiscriminatorDeepDecorrel,*JetsAK8_lean,*JetsAK8_momenthalf,*JetsAK8_NsubjettinessTau1,*JetsAK8_NsubjettinessTau2,*JetsAK8_NsubjettinessTau3,*Photons_genMatched,*Photons_hadTowOverEM,*Photons_hasPixelSeed,*Photons_isEB,*Photons_passElectronVeto,*Photons_pfChargedIso,*Photons_pfChargedIsoRhoCorr,*Photons_pfGammaIso,*Photons_pfGammaIsoRhoCorr,*Photons_pfNeutralIso,*Photons_pfNeutralIsoRhoCorr,*Photons_sigmaIetaIeta,*TAPElectronTracks_activity,*TAPElectronTracks_mT,*TAPElectronTracks_trkiso,*TAPMuonTracks_activity,*TAPMuonTracks_mT,*TAPMuonTracks_trkiso, *TAPPionTracks_activity,*TAPPionTracks_mT,*TAPPionTracks_trkiso;

   vector<TLorentzVector> *Photons=0, *Muons=0,*Electrons=0, *Jets = 0,*TAPElectronTracks=0,*JetsAK8=0,*JetsAK8Clean=0,*Jetsclean=0,*TAPMuonTracks=0,*ZCandidates=0;
   vector<string>  *TriggerNames=0;
   vector<vector<TLorentzVector> > *JetsAK8_subjets=0,*JetsAK8Clean_subjets=0,*TAPPionTracks=0;
   vector<vector<double> > *JetsAK8_subjets_axismajor=0,*JetsAK8_subjets_axisminor=0,*JetsAK8_subjets_bDiscriminatorCSV=0,*JetsAK8_subjets_ptD=0,*JetsAK8Clean_subjets_bDiscriminatorCSV=0;
   vector<vector<int> > *JetsAK8_subjets_multiplicity=0;
 

   TBranch *b_Photons=0;
   t1->SetBranchStatus("*",1);


   t1->SetBranchAddress("MET", &MET);
   t1->SetBranchAddress("HTclean", &HTclean);
   t1->SetBranchAddress("HT", &HT);
   t1->SetBranchAddress("MHT", &MHT);
   t1->SetBranchAddress("MHTclean", &MHTclean);
   t1->SetBranchAddress("MHTPhi", &MHTPhi);
   t1->SetBranchAddress("CaloMET", &CaloMET);
   t1->SetBranchAddress("CaloMETPhi", &CaloMETPhi);
   t1->SetBranchAddress("MT2", &MT2);
   t1->SetBranchAddress("DeltaPhi1", &DeltaPhi1);
   t1->SetBranchAddress("DeltaPhi2", &DeltaPhi2);
   t1->SetBranchAddress("DeltaPhi3", &DeltaPhi3);
   t1->SetBranchAddress("DeltaPhi4",&DeltaPhi4);
   t1->SetBranchAddress("PFCaloMETRatio", &PFCaloMETRatio);
   t1->SetBranchAddress("Photons",&Photons,&b_Photons);
   t1->SetBranchAddress("NJets", &NJets);
   t1->SetBranchAddress("isoElectronTracks", &isoElectronTracks);
   t1->SetBranchAddress("isoMuonTracks", &isoMuonTracks);
   t1->SetBranchAddress("isoPionTracks", &isoPionTracks);
   t1->SetBranchAddress("NVtx", &NVtx);
   t1->SetBranchAddress("nAllVertices", &nAllVertices);
   t1->SetBranchAddress("Muons",&Muons);
   t1->SetBranchAddress("Electrons",&Electrons);

   //TFile *output = TFile::Open("skim_output.root","RECREATE");            //output root file 
   TFile *output = TFile::Open(outputfile,"RECREATE");            //output root file 
   Int_t NJetsb,NVtxb,nAllVerticesb, isoElectronTracksb,isoMuonTracksb,isoPionTracksb;

   vector<TLorentzVector> *Photonsb=0,*Muonsb=0,*Electronsb=0;
   Double_t METb,HTcleanb,MHTPhib,CaloMETPhib,HTb, MHTb,MHTcleanb,CaloMETb,MT2b,DeltaPhi1b,DeltaPhi2b,DeltaPhi3b,DeltaPhi4b,PFCaloMETRatiob;

  TTree *tout = t1->CloneTree(0);  
  for(int r = 0; r < t1->GetEntries(); ++r) {
       t1->GetEntry(r);
       if(Photons->size() > 1  && Photons->at(0).Pt() > 100 && MHTclean > 200 && HTclean > 200){

          tout->Fill();
      
             }
  }
  cout<<"Total entries in skimmed file : "<<tout->GetEntries()<<"\n";
  output->Write();
  delete f;
  delete output;
  delete Photons,Muons,Electrons;

}

int main(int argc, char** argv)
{
    if(argc < 3)
      cout << "You have to provide two arguments!!\n";
    skim(argv[1],argv[2]);
    return 0;
}
