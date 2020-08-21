#!/bin/bash

#No original shell
#Test #1
ls frjegiujergi
echo $? > no_dollar_1.res

#Test #2
cat frjegiujergi
echo $? > no_dollar_2.res

#Test #3
echo frjegiujergi
echo $? > no_dollar_3.res

#Test #4
grep
echo $? > no_dollar_4.res

#Test #5
cd frjegiujergi
echo $? > no_dollar_5.res

#Test #6
../noroot.out
echo $? > no_dollar_6.res

#Test #7
/bin/ls
echo $? > no_dollar_7.res

#Test #8
$?
echo $? > no_dollar_8.res