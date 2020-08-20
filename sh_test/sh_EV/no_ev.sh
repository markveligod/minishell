#!/bin/bash

# No original shell
#Test #1 echo $PATH
echo $PATH > no_ev_1.res
sleep 4

#Test #2 echo $
echo $ > no_ev_2.res
sleep 4

#Test #3 echo $?
echo $? > no_ev_3.res
sleep 4

#Test #4 echo $toto
echo $toto > no_ev_4.res
sleep 4

#Test #5 echo $toto $LANG
echo $toto $LANG > no_ev_5.res
sleep 4

#Test #6 echo $toto $TOTO
echo $toto $TOTO > no_ev_6.res
sleep 4

#Test #7 echo $A $B
export A=123456789 B=Hello!World
echo $A $B > no_ev_7.res
sleep 4