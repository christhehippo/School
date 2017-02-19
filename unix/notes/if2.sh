#!/bin/bash
#
# if2.sh - moar fun
#

# if file27 "e"xists
if [ -e "file27" ]; then
	echo "file27 has `cat file27 | wc -l` lines"
fi

# if file 27 exists and is "r"eadable
if [ -r "file27" ] && [ -w "file27" ]; then 
	echo "file27 contains: `cat file27`"
fi

exit 0

