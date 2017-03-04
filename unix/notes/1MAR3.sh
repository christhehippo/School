#!/bin/bash
#
# array fun 2
#
declare -A message
message[mountain]="red"
message[dog]="keyboard"
message[ate]="necco wafers"
message[the]="spork"

for index in `cat msg`; do
	echo -m "${message[${index}]} "
done
echo

exit 0
