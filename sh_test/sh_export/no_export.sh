#!/bin/bash

#No original shell
#Test #1
export a=HelloWorld
export > no_export_1.res

#Test #2
export f g h j e a
export > no_export_2.res

#Test #3
export e w qw=wq t frf
export > no_export_3.res

#Test #4
export =grgrfegaegre
export > no_export_4.res