####Feb 27, 2017####
####Class Script####
####################
#!/bin/bash
####################
####################

echo -n "Pick the ending value: "
read final

echo -n "Pick the starting value: "
read start

while [ "${start}" -le "${final}" ]; do
	echo -n "${start} "
	let start=start+1
done
echo 






exit 0
