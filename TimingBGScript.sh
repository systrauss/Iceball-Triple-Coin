#!/bin/tcsh

#$ -M sstrauss@nd.edu
#$ -m a
#$ -q long
#$ -N ICE_Trip
#$ -o logs/
#$ -t 16-90
#$ -j y

module load /afs/crc.nd.edu/user/n/nsl/nuclear/startup/nsl
module load root/6.02
root-config --version
cd /afs/crc.nd.edu/group/nsl/nuc/users/sstrauss/Github/Iceball-Triple-Coin
echo "start task ${SGE_TASK_ID}"
date
./main $SGE_TASK_ID Cut_123_797_Timing_BG 123 797 0.3 0.9
echo "ended task ${SGE_TASK_ID}"
date

exit $?
