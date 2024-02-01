#!/bin/bash

#This jobscript runs in 10 parallel jobs

funct_Call(){
    # Incase we also want to compile and execute here
    #g++ p1.cpp -o output$1.out
    #echo $1 | ./output$1.out

    echo $1 | ./a.out > job$1.txt
}

#User input to get the n
read -p "Give n: " n 

for ((i=1; i<=n;i++));
do
    funct_Call $i &
done

wait

echo "All done"

