# skim

Compile the skimming script, skim.C

./compile.sh

Create executable corresponding to an Era and # of files.

source createJobs.sh era nfile

#for e.g.:

source createJobs.sh B 25

It will produce run_B.sh, batch_B.jdl

Then, submit the condor job. For e.g. :

condor_submit batch_B.jdl
