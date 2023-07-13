#!/bin/sh
DIR="/home/manfred/dev/primtive-ai/dual-input"
cd $DIR
#ITER=500
gcc ./dual-input.c -o ./main -lm
./main 500 && rm main
