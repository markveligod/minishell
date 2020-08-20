#!/bin/bash

#Original shell
# Test #1 empty 'unset'
unset
env > or_unset_1.res

# Test #2 'unset LANG'
unset LANG
env > or_unset_2.res

# Test #3 'unset HOSTTYPE LS_COLORS'
unset HOSTTYPE LS_COLORS
env > or_unset_3.res

# Test #4 'unset girejgiej'
unset girejgiej
env > or_unset_4.res

# Test #5 'unset girejgiej gh'
unset girejgiej gh
env > or_unset_5.res

# Test #6 'unset a b c d e f'
export a=123 b=2 c=3 d=4 e=a f=000
unset a b c d e f
env > or_unset_6.res