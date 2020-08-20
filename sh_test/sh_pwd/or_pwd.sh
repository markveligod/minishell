#!/bin/bash

#Original shell
#Test #1 pwd <empty>
pwd > or_pwd_1.res

#Test #2 pwd arg
pwd arg > or_pwd_2.res

#Test #3 pwd pwd
pwd pwd > or_pwd_3.res

#Test #4 pwd arg arg
pwd arg arg > or_pwd_4.res

#Test #5 pwd with cd ..
cd ..
cd $OLDPWD
pwd > or_pwd_5.res