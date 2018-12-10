#!/bin/bash

cd ${_CONDOR_SCRATCH_DIR}

#Setup area to get correct root versions
echo "source /cvmfs/cms.cern.ch/cmsset_default.sh"
source /cvmfs/cms.cern.ch/cmsset_default.sh

echo "scramv1 project CMSSW CMSSW_8_0_26_patch1"
scramv1 project CMSSW CMSSW_8_0_26_patch1

echo "cd CMSSW_8_0_26_patch1/src/"
cd CMSSW_8_0_26_patch1/src/

echo "eval `scramv1 runtime -sh`"
eval `scramv1 runtime -sh`

echo "cd ../.."
cd ../..

# For compiling skim.C file & making executable
g++ `root-config --cflags` skim.C -o skim.exe `root-config --libs` 


##Get input and output flags
i=F
j=$1
input="Run2017${i}-31Mar2018-v1.SinglePhoton_${j}_RA2AnalysisTree.root"
echo $input

output="skim_SinglePhoton_${i}_${j}.root" 
echo $output

echo "./skim.exe root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Run2ProductionV15/$input $output"

./skim.exe root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Run2ProductionV15/$input $output

echo "xrdcp $output root://cmseos.fnal.gov//store/user/tmishra/skim_SinglePhoton_condor/$output"

xrdcp $output root://cmseos.fnal.gov//store/user/tmishra/skim_SinglePhoton_condor/$output
