#############gfo0 by Christian Cattell############
#!/bin/bash
#

## Clear out prior data incase it is there
rm -f statusunix.txt
rm -f projectdata.txt

## Record the status data into a txt file
status unix > statusunix.txt

## Create variable for number of lines from last line to line with 'PROJECTS'
PROJECTLINE=$(cat -n statusunix.txt | grep PROJECTS | sed 's/[^0-9]//g')

## Isolate the project data with a common delimiter 
cat statusunix.txt | tail -$(($PROJECTLINE-1)) | head -11 | sed 's/ /:/g' > pdTEMP1.txt
cat pdTEMP1.txt | cut -c5- | sed 's/(//g' | sed 's/)//g' > pdTEMP2.txt
cat pdTEMP2.txt | sed 's/\//:/g' > projectdata.txt
## Remove temp files, had to use since char limit on line
rm -f pdTEMP[1-2].txt

## Variable for total number of projects + 1(bonus)
PROJECTCOUNT=$(wc -l projectdata.txt | sed 's/[^0-9]//g')
##Random extra line in projectdata that doesnt want to go away messing up this value so fixing it below
PROJECTCOUNT=$(($PROJECTCOUNT-1))

######################################################
## Start the output, this many eq signs always present
printf "=========="
## Add 5 eq signs for each project
EQLOOP1=1
while [ $EQLOOP1 -lt $PROJECTCOUNT ]
do
	printf "=====" 
	EQLOOP1=$(($EQLOOP1+1))
done
## Add final eq signs that are always present
printf "=================================\n"

####################################################
## Next line of output
printf "UNIX      "
PLOOP1=1
while [ $PLOOP1 -lt $PROJECTCOUNT ]
do
	if [ $PLOOP1 = 1 ]
	then
		cat projectdata.txt | head -$PLOOP1 | cut -d : -f2 | tr -d '\n'
		printf " "
	else
		cat projectdata.txt | head -$PLOOP1 | tail -1 | cut -d : -f2 | tr -d '\n'
		printf " "
	fi
	PLOOP1=$(($PLOOP1+1))
done
printf "bns prjct+ptcpn+jrnal = result\n"

####################################################
## Third line of output,  all eq signs 
printf "=========="
EQLOOP2=1
while [ $EQLOOP2 -lt $PROJECTCOUNT ]
do
	printf "=====" 
	EQLOOP2=$(($EQLOOP2+1))
done
printf "=================================\n"

####################################################
## Fourth line of output start, below print username
printf "%8s: " "$LOGNAME"
PLOOP2=1
## Print project score in this loop
while [ $PLOOP2 -le $PROJECTCOUNT ]
do
	if [ $PLOOP2 = 1 ]
	then
		ESCORE=$(cat projectdata.txt | cut -d : -f7 | head -$PLOOP2 | tr -d '\n')
	else
		ESCORE=$(cat projectdata.txt | cut -d : -f7 | head -$PLOOP2 | tail -1 | tr -d '\n')
	fi
	## Calculate the score earned in this loop also
	PROJECTTOTAL=$(($PROJECTTOTAL+$ESCORE))
	
	if [ $PLOOP2 = $PROJECTCOUNT ]
	then
		printf "%-4d" "$ESCORE"
	else
		printf "%-5d" "$ESCORE"
	fi
	
	PLOOP2=$(($PLOOP2+1))
done

PLOOP3=1
## Loop to calculate max possible points
while [ $PLOOP3 -le $PROJECTCOUNT ]
do
	if [ $PLOOP3 = 1 ]
	then
		MSCORE=$(cat projectdata.txt | cut -d : -f8 | head -$PLOOP3 | tr -d '\n')
	else
		MSCORE=$(cat projectdata.txt | cut -d : -f8 | head -$PLOOP3 | tail -1 | tr -d '\n')
	fi
	## Calculate the MAX score
	PROJECTTOTALMAX=$(($PROJECTTOTALMAX+$MSCORE))
	PLOOP3=$(($PLOOP3+1))
done

## Score out of 52 calculated
SCOREOUTOF52=$(((52 * $PROJECTTOTAL) / $PROJECTTOTALMAX))

printf "%d/52" "$SCOREOUTOF52"









	
