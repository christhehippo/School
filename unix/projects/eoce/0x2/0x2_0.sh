##UNIX EOCE 0x2 SCRIPT 1 -- CHRISTIAN CATTELL##
#
#!/bin/bash
#

## Obtain word for checking
printf "Enter a word: "
read INPUT

## Length of the string
LENGTH=${#INPUT}

## Interval for check loop
i=0
while [ $i -lt $(($LENGTH-$i)) ]
do
	## Left-hand letter
	LF=$(echo ${INPUT:$i:1})
	## Right-hand letter
	LL=$(echo ${INPUT:$((LENGTH-$((i+1)))):1})
	
	## Are the letters equal? If not then exit
	if [ $LF != $LL ]
	then
		printf "\n%s is not a palindrome.\n\n" "$INPUT"
		exit
	fi
	i=$((i+1))
done 

printf "\n%s is a palindrome.\n\n" "$INPUT"

exit
