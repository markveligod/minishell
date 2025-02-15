#!/bin/bash

# No original shell
# Test #1 empty 'unset'
unset
env > no_unset_1.res
sleep 4

# Test #2 'unset LANG'
unset LANG
env > no_unset_2.res
sleep 4

# Test #3 'unset HOSTTYPE LS_COLORS'
unset HOSTTYPE LS_COLORS
env > no_unset_3.res
sleep 4

# Test #4 'unset girejgiej'
unset girejgiej
env > no_unset_4.res
sleep 4

# Test #5 'unset girejgiej gh'
unset girejgiej gh
env > no_unset_5.res
sleep 4

# Test #6 'unset a b c d e f'
export a=123 b=2 c=3 d=4 e=a f=000
unset a b c d e f
env > no_unset_6.res
sleep 4