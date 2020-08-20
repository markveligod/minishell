#!/bin/bash

#No original shell
#Test #1 ./a.out
./a.out > no_rp_1.res

#Test #2 ../a.out
../a.out > no_rp_2.res

#Test #3 ../noroot.out
../noroot.out > no_rp_3.res

#Test #4 ../no.out
../no.out > no_rp_4.res