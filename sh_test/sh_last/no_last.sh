#!/bin/bash

#No original shell
#Test #1
echo Hello > no_last_1.res | >> no_last_1.res echo World | ./get_next_line < diff_last.sh >> no_last_1.res | env | grep LANG >> no_last_1.res | env | grep PWD >> no_last_1.res | cat diff_last.sh | grep diff >> no_last_1.res
sleep 4

#Test #2
> no_last_2.res toto | env | grep LANG >>no_last_2.res ;
sleep 4

#Test #3
cat diff_last > no_last_3.res | env | grep NAME > no_last_3.res | ./get_next_line < diff_last.sh >>no_last_3.res
sleep 4

#Test #4
> no_last_4.res cat gehujgiofkoppereijgtr jierogtuerifwopehut fowpkeeijgtorre fopreijgtorjeipwo > no_last_4.res | hugjifkeofrj guerijofwkijtogg kgitjhyjreifewokijgt echo Hello World >> no_last_4.res
sleep 4