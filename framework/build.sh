#!/bin/sh
#set -xe
clang -Wall -Wextra main.c -o main.out -lm \
&& ./main.out \
&& rm main.out