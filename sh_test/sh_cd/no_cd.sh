#!/bin/bash

# No original shell
#Test #1 cd <empty>
cd > no_cd_1.res
cd $OLDPWD
env | grep pwd >> no_cd_1.res

#Test #2 cd .
cd . > no_cd_2.res
env | grep pwd >> no_cd_2.res

#Test #3 cd ..
cd .. > no_cd_3.res
cd $OLDPWD
env | grep pwd >> no_cd_3.res

#Test #4 cd no_cd.sh
> no_cd_4.res cd no_cd.sh
env | grep PWD >> no_cd_4.res

#Test #5 cd no_cd.sh or_cd.sh
> no_cd_5.res cd no_cd.sh or_cd.sh
env | grep PWD >> no_cd_5.res

#Test #6 cd /bin
cd /bin > no_cd_6.res
cd $OLDPWD
env | grep PWD >> no_cd_6.res