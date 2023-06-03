#!/bin/sh
DIR="/home/manfred/dev/ai-model"
cd $DIR
#ITER=500
gcc ./main.c -o ./main -lm
./main 500