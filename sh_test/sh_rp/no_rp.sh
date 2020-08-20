#!/bin/bash

#No original shell
#Test #1 ./a.out
./a.out > no_rp_1.res
sleep 4

#Test #2 ../a.out
../a.out > no_rp_2.res
sleep 4

#Test #3 ../noroot.out
../noroot.out > no_rp_3.res
sleep 4

#Test #4 ../no.out
../no.out > no_rp_4.res
sleep 4