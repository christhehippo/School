#!/bin/bash
#
# Execute this with some quantity of arguments:
#   ./0x0 4 37 16 23 11 8 29 0 32 2 43 5.2 1 3.14 19
#

## Find the biggest arguement
biggest=0
for item in ${*}; do
	if [ ${item} -gt ${biggest} ]
	then
		biggest=${item}
	fi
done

function evaluate()
{
    value="${1}"
	## Instead of sleeping for $1 seconds, sleep for the biggest number minus $1 seconds
	## so the biggest number instantly prints, then the next biggest and next and so on..
    sleep  "$((biggest-${1}))" && printf "${1} "
}

for item in ${*}; do
	evaluate "${item}" &
done
wait
echo

exit 0
