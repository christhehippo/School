#!/bin/bash
#
# funwithifs.sh - practice with if statements
#

echo -n "Please enter a number between 1 and 100: "
read number
# Basic 6 relation operators (bash script)
# -eq   is equal to
# -ne   is not equal to
# -lt   is less than
# -gt   is greater than
# -le   is less than or equal
# -ge   is greater than or equal to

evenchk=$(echo "${nubmer}%2" | bc -q)

if [ "${number}" -lt 50 ] && [ "${evenchk}" -eq 0 ]; then 
	echo "Input was less than fifty AND EVEN"
elif [ "${number}" -lt 50 ]; then
	echo "Input was less than fifty"
elif [ "${number}" -gt 50 ]; then
	echo "Input was not less than fifty"
else 
	echo "Input equals fifty"
fi

echo "You entered ${number}"

exit 0

