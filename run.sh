#!/bin/bash

algo=("selection" "insertion" "merge" "quick" "hybrid")
n=(1000 5000 10000 50000 75000 100000 500000)


for i in "${n[@]}"; do
    rm -r $i
    mkdir $i
    python runscript.py $i ./${i}/unsorted_${i}.txt
    ./a.exe 3 ./${i}/unsorted_${i}.txt ./${i}/sorted_${i}.txt ./${i}/x.txt
done

for i in "${n[@]}"; do
    echo $i
    COUNTER=0
    for j in "${algo[@]}"; do
        ./a.exe $COUNTER ./${i}/unsorted_${i}.txt ./${i}/sorted_${j}_${i}.txt ./${i}/time_${j}_${i}.txt
        ./a.exe $COUNTER ./${i}/sorted_${i}.txt ./${i}/sorted_${j}_${i}.txt ./${i}/t_${j}_${i}.txt
        let COUNTER+=1
    done
done