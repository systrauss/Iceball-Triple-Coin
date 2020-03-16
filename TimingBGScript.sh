#!/bin/tcsh

#$ -M sstrauss@nd.edu
#$ -m a
#$ -q long
#$ -N ICEDecBG
#$ -o logs/
#$ -t 45-70
#$ -j y

module load /afs/crc.nd.edu/user/n/nsl/nuclear/startup/nsl
module load root/6.02
root-config --version
cd /afs/crc.nd.edu/group/nsl/nuc/users/sstrauss/iceball_dec2014/Code/Iceball-Coin-Energy
echo "start task ${SGE_TASK_ID}"
date
./main $SGE_TASK_ID Cut_154J2J_Timing_BG 154J2J Timing_BG
echo "ended task ${SGE_TASK_ID}"
date

exit $?
