void ntuple_merge() {
  
   TChain chainB("PreSelection"); //name of ntuple
   TString name;

   for(int i=0; i<=613; i++) {
      name.Form("%d",i);
      chainB.Add("/eos/uscms/store/user/tmishra/skim_JetHT_condor//eos/uscms/store/user/tmishra/skim_JetHT_condor/skim_JetHT_B_"+name+".root");
   }
   chainB.Merge("skim_JetHT_B.root");
   
   
   
   TChain chainC("PreSelection"); //name of ntuple

   for(int i=0; i<=940; i++) {
      name.Form("%d",i);
      chainC.Add("/eos/uscms/store/user/tmishra/skim_JetHT_condor//eos/uscms/store/user/tmishra/skim_JetHT_condor/skim_JetHT_C_"+name+".root");
   }
   chainC.Merge("skim_JetHT_C.root");
   
   
   
   
   TChain chainD("PreSelection"); //name of ntuple

   for(int i=0; i<=437; i++) {
      name.Form("%d",i);
      chainD.Add("/eos/uscms/store/user/tmishra/skim_JetHT_condor//eos/uscms/store/user/tmishra/skim_JetHT_condor/skim_JetHT_D_"+name+".root");
   }
   chainD.Merge("skim_JetHT_D.root");
   
   
   
   
   TChain chainE("PreSelection"); //name of ntuple

   for(int i=0; i<=1028; i++) {
      name.Form("%d",i);
      chainE.Add("/eos/uscms/store/user/tmishra/skim_JetHT_condor//eos/uscms/store/user/tmishra/skim_JetHT_condor/skim_JetHT_E_"+name+".root");
   }
   chainE.Merge("skim_JetHT_E.root");
   
   
   
   
   TChain chainF("PreSelection"); //name of ntuple

   for(int i=0; i<=1269; i++) {
      name.Form("%d",i);
      chainF.Add("/eos/uscms/store/user/tmishra/skim_JetHT_condor//eos/uscms/store/user/tmishra/skim_JetHT_condor/skim_JetHT_F_"+name+".root");
   }
   chainF.Merge("skim_JetHT_F.root");


}



