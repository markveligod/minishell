#!/bin/bash

#Original shell
#Test #1 (with $PATH)
ls | grep diff > or_ep_1.res; wc -l diff_ep.sh > or_ep_2.res; cat diff_ep.sh > or_ep_3.res;

export TEMP=$PATH
unset PATH
#Test #2 (without $PATH)
ls | grep diff > or_ep_4.res; wc -l diff_ep.sh > or_ep_5.res; cat diff_ep.sh > or_ep_6.res;

export PATH=$TEMP
unset TEMP

#Test #3 (with $PATH)
ls | grep diff > or_ep_7.res; wc -l diff_ep.sh > or_ep_8.res; cat diff_ep.sh > or_ep_9.res;