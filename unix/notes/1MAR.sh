#!/bin/bash
#
# arraryfun
#
data[${index}]="things"
let index=index+1
data[${index}]=80
let index=index+1
data[${index}]=3.1337
let index=index+2
data[${index}]='a'
for index in 0 1 2 4; do
	echo "#${index} is: ${data[${index}]}"
done

exit 0
