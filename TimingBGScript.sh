#!/bin/tcsh

#$ -M sstrauss@nd.edu
#$ -m a
#$ -q long
#$ -N ICE1237
#$ -o logs/
#$ -t 18-77
#$ -j y

module load /afs/crc.nd.edu/user/n/nsl/nuclear/startup/nsl
module load root/6.02
root-config --version
cd /afs/crc.nd.edu/group/nsl/nuc/users/sstrauss/Github/ICEBall-Coincidence-Code
echo "start task ${SGE_TASK_ID}"
date
./main $SGE_TASK_ID Cut_1237_Timing_BG 1237 0.3 0.9
echo "ended task ${SGE_TASK_ID}"
date

exit $?
