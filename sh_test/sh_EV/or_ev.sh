#!/bin/bash

#Original shell
#Test #1 echo $PATH
echo $PATH > or_ev_1.res

#Test #2 echo $
echo $ > or_ev_2.res

#Test #3 echo $?
echo $? > or_ev_3.res

#Test #4 echo $toto
echo $toto > or_ev_4.res

#Test #5 echo $toto $LANG
echo $toto $LANG > or_ev_5.res

#Test #6 echo $toto $TOTO
echo $toto $TOTO > or_ev_6.res

#Test #7 echo $A $B
export A=123456789 B=Hello!World
echo $A $B > or_ev_7.res