####Feb 27, 2017####
####Class Script####
####################
#!/bin/bash
####################
####################
###LIST FOR LOOP####


echo -n "Pick the ending value: "
read final

echo -n "Pick the starting value: "
read start

#for value in 2 3 4 5 6 7 8 9 10; do
for value in `seq -s ' ' ${start} ${final}`; do
	echo -n "${value} "
done
echo

exit 0
