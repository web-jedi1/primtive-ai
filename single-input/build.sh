#!/bin/sh
DIR="/home/manfred/dev/primtive-ai/single-input"
cd $DIR
#ITER=500
gcc ./main.c -o ./main -lm
./main 500 && rm main