#!/bin/bash

#Original shell
#Test #1
ls frjegiujergi
echo $? > or_dollar_1.res

#Test #2
cat frjegiujergi
echo $? > or_dollar_2.res

#Test #3
echo frjegiujergi
echo $? > or_dollar_3.res

#Test #4
grep
echo $? > or_dollar_4.res

#Test #5
cd frjegiujergi
echo $? > or_dollar_5.res

#Test #6
../noroot.out
echo $? > or_dollar_6.res

#Test #7
/bin/ls
echo $? > or_dollar_7.res

#Test #8
$?
echo $? > or_dollar_8.res