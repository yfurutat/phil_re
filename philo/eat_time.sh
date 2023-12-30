#!/bin/bash

# file="output.txt"
file="phil_out.txt"

for i in {1..200}; do
    count=$(grep -c " ${i} is eating" "$file")
    echo "$i is eating: $count times"
done