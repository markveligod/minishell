#!/bin/bash

#No original shell
#Test #1 pwd <empty>
pwd > no_pwd_1.res
sleep 4

#Test #2 pwd arg
pwd arg > no_pwd_2.res
sleep 4

#Test #3 pwd pwd
pwd pwd > no_pwd_3.res
sleep 4

#Test #4 pwd arg arg
pwd arg arg > no_pwd_4.res
sleep 4

#Test #5 pwd with cd ..
cd ..
cd $OLDPWD
pwd > no_pwd_5.res
sleep 4
