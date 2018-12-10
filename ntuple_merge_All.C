void ntuple_merge_All() {
  
   TChain chain("PreSelection"); //name of ntuple

      chain.Add("skim_output_B.root");
      chain.Add("skim_output_C.root");
      chain.Add("skim_output_D.root");
      chain.Add("skim_output_E.root");
      chain.Add("skim_output_F.root");
      chain.Merge("skim_output_All.root");


}



