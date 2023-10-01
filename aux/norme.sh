#! /usr/bin/env bash

norm() {
    python3 -m c_formatter_42 < $1 > temp
    mv temp $1
}

SRC_DIR='./src'
H_DIR='./src'

C_FILES=$(find $SRC_DIR -name '*.c')
H_FILES=$(find $H_DIR -name '*.h')

TO_NORM="$C_FILES $H_FILES"

for file in $TO_NORM; do
    norm $file
done
