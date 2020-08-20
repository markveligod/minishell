#!/bin/bash

#Original shell
#Test #1 cd <empty>
cd > or_cd_1.res
cd $OLDPWD
env | grep pwd >> or_cd_1.res

#Test #2 cd .
cd . > or_cd_2.res
env | grep pwd >> or_cd_2.res

#Test #3 cd ..
cd .. > or_cd_3.res
cd $OLDPWD
env | grep pwd >> or_cd_3.res

#Test #4 cd no_cd.sh
cd no_cd.sh > or_cd_4.res
env | grep PWD >> or_cd_4.res

#Test #5 cd no_cd.sh or_cd.sh
cd no_cd.sh or_cd.sh > or_cd_5.res
env | grep PWD >> or_cd_5.res

#Test #6 cd /bin
cd /bin > or_cd_6.res
cd $OLDPWD
env | grep PWD >> or_cd_6.res