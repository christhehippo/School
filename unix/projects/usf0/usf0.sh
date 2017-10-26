#!/bin/bash
#
#
##I left the signed stuff in there in case I come back and try to do it
startingValue=$1
endingValue=$2
displaySigned=$3
spaceCheatHex="0x"
prettyLine="----------+----------+----------+----------"
prettySignedLine="----------+----------+----------+----------+----------"

##Does this count as not manually doing spaces?
 lt16Space=" "
 lt32Space=" "
 lt64Space=" "
lt128Space=" "
gt128Space=" "

if [ -z $1 ]
  then
  	startingValue=0
fi

if [ -z $2 ]
  then
  	endingValue=15
fi

if [ -z $3 ]
  then
  	displaySigned=0
  else
  	printf "SIGNED FUNCTIONALITY NOT IMPLEMENTED\n"
	exit 
fi


printf "  base 2  |  base 8  |  base10  |"
##if [ $displaySigned -gt 0 ]
##  then 
##  	printf "  signed  |"
##fi
printf "  base16  \n"
printf "%s\n" $prettyLine

while [ $startingValue -le $endingValue ]
do
	##Had to cheat a little bit here, I kind of know what this all does though
	##The double printf is because the cut command prints a newline by default so I sent everything to another printf
	##Only prints 4 places if less than 16, then adds a digits place for 2^n 
	if [ $startingValue -lt 16 ]
	  then
	    printf "%5s" $lt16Space
		printf '%s' $(printf "%s %04d 0x%02x" "$startingValue" $(bc <<< "ibase=10;obase=2;$startingValue") "$startingValue" |	cut -d ' ' -f2)  
		
	elif [ $startingValue -lt 32 ]
	  then
	    printf "%4s" $lt32Space
		printf '%s' $(printf "%s %05d 0x%02x" "$startingValue" $(bc <<< "ibase=10;obase=2;$startingValue") "$startingValue" | cut -d ' ' -f2	)
	elif [ $startingValue -lt 64 ]
	  then
	    printf "%3s" $lt64Space
		printf '%s' $(printf "%s %06d 0x%02x" "$startingValue" $(bc <<< "ibase=10;obase=2;$startingValue") "$startingValue" | cut -d ' ' -f2)	
	elif [ $startingValue -lt 128 ]
	  then
	    printf "%2s" $lt128Space
		printf '%s' $(printf "%s %07d 0x%02x" "$startingValue" $(bc <<< "ibase=10;obase=2;$startingValue") "$startingValue" | cut -d ' ' -f2)
	else 
	    printf "%1s" $gt128Space
		printf '%s' $(printf "%s %08d 0x%02x" "$startingValue" $(bc <<< "ibase=10;obase=2;$startingValue") "$startingValue" | cut -d ' ' -f2)	
	fi
		
	printf " |"
	##Octal print
	printf "%9.03o |" $startingValue
	##Normal numbers
	printf "%9i |" $startingValue
	
##	if [$displaySigned -gt 0]
##	  then
##	  	printf
	##Hex conversion, I cheated a little with the spacing because I couldnt get the 0x to line up properly for some reason
	printf "%7s" $spaceCheatHex
	printf "%02X\n" $startingValue	
	
	
	((startingValue++))
done
exit
