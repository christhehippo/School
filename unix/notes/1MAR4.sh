#!/bin/bash
#
# array fun 4
#

echo "This script ($[0]) was called with ${#} arguements."
echo "They are:"

count=1
for arg in ${*}; do
	echo "arg #${count}: ${arg}"
	let count=count+1
done

exit 0

