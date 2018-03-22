#!/bin/bash
 
starting=`gettimeofday`
 
${1} 2>/dev/null
 
end=`gettimeofday`
 
total=`bc <<< "scale=5; ${end} - ${starting}"`
printf "%.3lf\n" "${total}"
 
exit 0
