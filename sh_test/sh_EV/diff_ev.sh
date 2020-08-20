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
TEST6='0'
TEST7='0'

#Now time to difffffffffffffffffffffffffff

echo -en "$CYAN[TEST #1] => 'echo \$PATH'$RESET       | "
if cmp or_ev_1.res no_ev_1.res &> /dev/null
then
TEST1='1'
echo -en "$GREEN[OK]$RESET"
echo ""
else
echo -en "$RED[FAIL]$RESET"
echo ""
diff --normal or_ev_1.res no_ev_1.res 
fi

echo -en "$CYAN[TEST #2] => 'echo \$'$RESET           | "
if cmp or_ev_2.res no_ev_2.res &> /dev/null
then
TEST2='1'
echo -en "$GREEN[OK]$RESET"
echo ""
else
echo -en "$RED[FAIL]$RESET"
echo ""
diff --normal or_ev_2.res no_ev_2.res 
fi

echo -en "$CYAN[TEST #3] => 'echo \$?'$RESET          | "
if cmp or_ev_3.res no_ev_3.res &> /dev/null
then
TEST3='1'
echo -en "$GREEN[OK]$RESET"
echo ""
else
echo -en "$RED[FAIL]$RESET"
echo ""
diff --normal or_ev_3.res no_ev_3.res 
fi

echo -en "$CYAN[TEST #4] => 'echo \$toto'$RESET       | "
if cmp or_ev_4.res no_ev_4.res &> /dev/null
then
TEST4='1'
echo -en "$GREEN[OK]$RESET"
echo ""
else
echo -en "$RED[FAIL]$RESET"
echo ""
diff --normal or_ev_4.res no_ev_4.res 
fi

echo -en "$CYAN[TEST #5] => 'echo \$toto \$LANG'$RESET | "
if cmp or_ev_5.res no_ev_5.res &> /dev/null
then
TEST5='1'
echo -en "$GREEN[OK]$RESET"
echo ""
else
echo -en "$RED[FAIL]$RESET"
echo ""
diff --normal or_ev_5.res no_ev_5.res 
fi

echo -en "$CYAN[TEST #6] => 'echo \$toto \$TOTO'$RESET | "
if cmp or_ev_6.res no_ev_6.res &> /dev/null
then
TEST6='1'
echo -en "$GREEN[OK]$RESET"
echo ""
else
echo -en "$RED[FAIL]$RESET"
echo ""
diff --normal or_ev_6.res no_ev_6.res 
fi

echo -en "$CYAN[TEST #7] => 'echo \$A \$B'$RESET       | "
if cmp or_ev_7.res no_ev_7.res &> /dev/null
then
TEST7='1'
echo -en "$GREEN[OK]$RESET"
echo ""
else
echo -en "$RED[FAIL]$RESET"
echo ""
diff --normal or_ev_7.res no_ev_7.res 
fi

#Delete all!!!
CHECK='1'
if [ "$TEST1" -eq "$CHECK" ]
then
rm or_ev_1.res no_ev_1.res
fi

if [ "$TEST2" -eq "$CHECK" ]
then
rm or_ev_2.res no_ev_2.res
fi

if [ "$TEST3" -eq "$CHECK" ]
then
rm or_ev_3.res no_ev_3.res
fi

if [ "$TEST4" -eq "$CHECK" ]
then
rm or_ev_4.res no_ev_4.res
fi

if [ "$TEST5" -eq "$CHECK" ]
then
rm or_ev_5.res no_ev_5.res
fi

if [ "$TEST6" -eq "$CHECK" ]
then
rm or_ev_6.res no_ev_6.res
fi

if [ "$TEST7" -eq "$CHECK" ]
then
rm or_ev_7.res no_ev_7.res
fi