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

#Now time to difffffffffffffffffffffffffff

echo -en "$CYAN[TEST #1] => 'ls | grep diff; wc -l diff_ep.sh; cat diff_ep.sh; (with \$PATH)'$RESET    | "
if cmp or_ep_1.res no_ep_1.res &> /dev/null && cmp or_ep_2.res no_ep_2.res &> /dev/null && cmp or_ep_3.res no_ep_3.res &> /dev/null
then
TEST1='1'
echo -en "$GREEN[OK]$RESET"
echo ""
else
echo -en "$RED[FAIL]$RESET"
echo ""
diff --normal or_ep_1.res no_ep_1.res
diff --normal or_ep_2.res no_ep_2.res
diff --normal or_ep_3.res no_ep_3.res 
fi

echo -en "$CYAN[TEST #2] => 'ls | grep diff; wc -l diff_ep.sh; cat diff_ep.sh; (without \$PATH)'$RESET | "
if cmp or_ep_4.res no_ep_4.res &> /dev/null && cmp or_ep_5.res no_ep_5.res &> /dev/null && cmp or_ep_6.res no_ep_6.res &> /dev/null
then
TEST2='1'
echo -en "$GREEN[OK]$RESET"
echo ""
else
echo -en "$RED[FAIL]$RESET"
echo ""
diff --normal or_ep_4.res no_ep_4.res
diff --normal or_ep_5.res no_ep_5.res
diff --normal or_ep_6.res no_ep_6.res 
fi

echo -en "$CYAN[TEST #3] => 'ls | grep diff; wc -l diff_ep.sh; cat diff_ep.sh; (with \$PATH)'$RESET    | "
if cmp or_ep_7.res no_ep_7.res &> /dev/null && cmp or_ep_8.res no_ep_8.res &> /dev/null && cmp or_ep_9.res no_ep_9.res &> /dev/null
then
TEST3='1'
echo -en "$GREEN[OK]$RESET"
echo ""
else
echo -en "$RED[FAIL]$RESET"
echo ""
diff --normal or_ep_7.res no_ep_7.res
diff --normal or_ep_8.res no_ep_8.res
diff --normal or_ep_9.res no_ep_9.res 
fi

#Delete all!!!
CHECK='1'
if [ "$TEST1" -eq "$CHECK" ]
then
rm or_ep_1.res no_ep_1.res
rm or_ep_2.res no_ep_2.res
rm or_ep_3.res no_ep_3.res
fi

if [ "$TEST2" -eq "$CHECK" ]
then
rm or_ep_4.res no_ep_4.res
rm or_ep_5.res no_ep_5.res
rm or_ep_6.res no_ep_6.res
fi

if [ "$TEST3" -eq "$CHECK" ]
then
rm or_ep_7.res no_ep_7.res
rm or_ep_8.res no_ep_8.res
rm or_ep_9.res no_ep_9.res
fi