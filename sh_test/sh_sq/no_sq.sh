#!/bin/bash

#No original shell
#Test #1
echo "'" > no_sq_1.res

#Test #2
echo '"' > no_sq_2.res

#Test #3
echo '"' "'" > no_sq_3.res

#Test #4
echo "''\\'"'''""' '\\"' "'" > no_sq_4.res

#Test #5
echo "$LANG '" '$TOTO "        \\      "''"                ' > no_sq_5.res