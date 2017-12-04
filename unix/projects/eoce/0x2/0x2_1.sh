##UNIX EOCE 0x2 SCRIPT 2 -- CHRISTIAN CATTELL##
#
#!/bin/bash
#

## Obtain word for checking
printf "Enter a word: "
read WORD

## Send word to file because idk how to do this without a file
rm -f word.txt
echo "$WORD" > word.txt

## Reverse the word with rev
DROW=$(rev word.txt)
rm -f word.txt

## Check with if statement
if [ $WORD != $DROW ]
then
	printf "\n%s is not a palindrome\n\n" "$WORD"
	exit
fi

## If the script made it this far then the word is a palindrome
printf "\n%s is a palindrome\n\n" "$WORD"

exit
