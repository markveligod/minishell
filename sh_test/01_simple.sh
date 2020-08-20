# VALID
/bin/ls;
sleep 2;
/usr/local/bin/valgrind;
sleep 2;
/usr/bin/make;
sleep 2;
/bin/echo;
sleep 2;
/bin/date;
sleep 2;
/bin/ln;
sleep 2;
/bin/ps;
sleep 2;

# INVALID
/sbin/ls;
sleep 2;
/xxx;
sleep 2;
/bin/ddate;
sleep 2;