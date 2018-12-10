
#!/bin/bash

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

#rootcling -f Dict.cc LinkDef.h                                                  
#perl -pi -e 's/#include <math.h>/#include <math.h>\n#include <map>/'
#g++ `root-config --cflags` -c Dict.cc                                                             
# Dict.cc define dictionary for TLorentzVector

# For compiling skim.C file & making executable
g++ `root-config --cflags` skim.C -o skim.exe `root-config --libs`                         

