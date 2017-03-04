#!/bin/bash
#
# function fun
#

function sum ()
{
	echo "my arguments: ${*}"

	total=0
	for item in ${*}; do
		let total=total+item
	done
	echo "sum: ${total}"
}

sum 2 4 6 8
sum ${*}



exit 0
