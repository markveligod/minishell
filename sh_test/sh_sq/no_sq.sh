#!/bin/bash

#No original shell
#Test #1
echo "'" > no_sq_1.res
sleep 4

#Test #2
echo '"' > no_sq_2.res
sleep 4

#Test #3
echo '"' "'" > no_sq_3.res
sleep 4

#Test #4
echo "''\\'"'''""' '\\"' "'" > no_sq_4.res
sleep 4

#Test #5
echo "$LANG '" '$TOTO "        \\      "''"                ' > no_sq_5.res
sleep 4