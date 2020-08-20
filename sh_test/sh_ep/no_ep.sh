#!/bin/bash

#no original shell
#Test #1 (with $PATH)
ls | grep diff > no_ep_1.res; wc -l diff_ep.sh > no_ep_2.res; cat diff_ep.sh > no_ep_3.res;
sleep 4

export TEMP=$PATH
unset PATH
#Test #2 (without $PATH)
ls | grep diff > no_ep_4.res; wc -l diff_ep.sh > no_ep_5.res; cat diff_ep.sh > no_ep_6.res;
sleep 4

export PATH=$TEMP
unset TEMP

#Test #3 (with $PATH)
ls | grep diff > no_ep_7.res; wc -l diff_ep.sh > no_ep_8.res; cat diff_ep.sh > no_ep_9.res;
sleep 4