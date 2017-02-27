####Feb 27, 2017####
####Class Script####
####################
#!/bin/bash
####################
####################
##NUMERIC FOR LOOP##
echo -n "Pick the ending value: "
read final

echo -n "Pick the starting value: "
read start

for((value=start; value <= final; value++)); do
	echo -n "${value} "
done
echo

exit 0
