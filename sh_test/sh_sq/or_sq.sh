#!/bin/bash

#Original shell
#Test #1
echo "'" > or_sq_1.res

#Test #2
echo '"' > or_sq_2.res

#Test #3
echo '"' "'" > or_sq_3.res

#Test #4
echo "''\\'"'''""' '\\"' "'" > or_sq_4.res

#Test #5
echo "$LANG '" '$TOTO "        \\      "''"                ' > or_sq_5.res