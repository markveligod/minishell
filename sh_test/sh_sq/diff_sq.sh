#!/bin/bash

#COLOR;
RED='\033[1;31m'
GREEN='\033[1;32m'
CYAN='\033[1;36m'
RESET='\033[0m'

#Var
TEST1='0'
TEST2='0'
TEST3='0'
TEST4='0'
TEST5='0'

#Now time to difffffffffffffffffffffffffff

echo -en "$CYAN[TEST #1] => 'echo "\'" '$RESET                | "
if cmp or_sq_1.res no_sq_1.res &> /dev/null
then
TEST1='1'
echo -en "$GREEN[OK]$RESET"
echo ""
else
echo -en "$RED[FAIL]$RESET"
echo ""
diff --normal or_sq_1.res no_sq_1.res 
fi

echo -en "$CYAN[TEST #2] => 'echo '\"''$RESET               | "
if cmp or_sq_2.res no_sq_2.res &> /dev/null
then
TEST2='1'
echo -en "$GREEN[OK]$RESET"
echo ""
else
echo -en "$RED[FAIL]$RESET"
echo ""
diff --normal or_sq_2.res no_sq_2.res 
fi

echo -en "$CYAN[TEST #3] => 'echo '\"' "\'"'$RESET             | "
if cmp or_sq_3.res no_sq_3.res &> /dev/null
then
TEST3='1'
echo -en "$GREEN[OK]$RESET"
echo ""
else
echo -en "$RED[FAIL]$RESET"
echo ""
diff --normal or_sq_3.res no_sq_3.res 
fi

echo -en "$CYAN[TEST #4] => 'echo "''\\'"'''""' '\\"' "\'"'$RESET           | "
if cmp or_sq_4.res no_sq_4.res &> /dev/null
then
TEST4='1'
echo -en "$GREEN[OK]$RESET"
echo ""
else
echo -en "$RED[FAIL]$RESET"
echo ""
diff --normal or_sq_4.res no_sq_4.res 
fi

echo -en "$CYAN[TEST #5] => 'echo "$LANG '" '$TOTO "...'$RESET    | "
if cmp or_sq_5.res no_sq_5.res &> /dev/null
then
TEST5='1'
echo -en "$GREEN[OK]$RESET"
echo ""
else
echo -en "$RED[FAIL]$RESET"
echo ""
diff --normal or_sq_5.res no_sq_5.res 
fi

#Delete all!!!
CHECK='1'
if [ "$TEST1" -eq "$CHECK" ]
then
rm or_sq_1.res no_sq_1.res
fi

if [ "$TEST2" -eq "$CHECK" ]
then
rm or_sq_2.res no_sq_2.res
fi

if [ "$TEST3" -eq "$CHECK" ]
then
rm or_sq_3.res no_sq_3.res
fi

if [ "$TEST4" -eq "$CHECK" ]
then
rm or_sq_4.res no_sq_4.res
fi

if [ "$TEST5" -eq "$CHECK" ]
then
rm or_sq_5.res no_sq_5.res
fi