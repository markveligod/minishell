#!/bin/bash

#Original shell
#Test #1
echo Hello > or_last_1.res | >> or_last_1.res echo World | ./get_next_line < diff_last.sh >> or_last_1.res | env | grep LANG >> or_last_1.res | env | grep PWD >> or_last_1.res | cat diff_last.sh | grep diff >> or_last_1.res

#Test #2
> or_last_2.res toto | env | grep LANG >>or_last_2.res ;

#Test #3
cat diff_last > or_last_3.res | env | grep NAME > or_last_3.res | ./get_next_line < diff_last.sh >>or_last_3.res

#Test #4
> or_last_4.res cat gehujgiofkoppereijgtr jierogtuerifwopehut fowpkeeijgtorre fopreijgtorjeipwo > or_last_4.res | hugjifkeofrj guerijofwkijtogg kgitjhyjreifewokijgt echo Hello World >> or_last_4.res
