##UNIX EOCE 0x3 -- CHRISTIAN CATTELL##
#
#!/bin/bash
#



if [ "$1" = "" ]
then


	for day in {01..31};
	do 	
		for hour in {00..23};
		do
			TZ=EST pom $day$hour >> moon.txt
		done
	done
	
	## Next full moon will be put in this file
	grep 'The Moon will be Full' moon.txt | head -1 > fullmoon0.txt
	awk '{print "The next full moon will be on " $1 " " $3 " " $4 " " $2 " at " $5 "."}' fullmoon0.txt > fullmoon1.txt
	## Read next full moon
	cat fullmoon1.txt 
fi

## year given
if [ "$1" != "" ]
then
	year="$1"
	## Fix if year is enter as 4 digits
	if [ $year -gt 100 ]
	then
		yearmath=$((year/100))
		yearmath=$((yearmath*100))
		year=$(($year-$yearmath))
		## Adjusts years < 10 to 0X
		if [ $year -lt 10 ]
		then
			year=$(echo "0$year")
		fi
	fi
	
	for month in {01..12}
	do
		for day in {01..31};
		do 	
			for hour in {00..23};
			do
				TZ=EST pom $year$month$day$hour >> moon.txt
			done
		done
	done
	
	## Create full moon schedule
	grep -E w..l?.?b?e?.Full moon.txt > fullmoon0.txt
	awk '{ if (a[$1 $2 $3 $4]++ == 0) printf $0; }' fullmoon0.txt > fullmoon1.txt
	cat fullmoon1.txt | sed 's/Full/Full\n/g' > fullmoon2.txt
	awk '{ if (a[$3]++ == 0) printf $0; }' fullmoon2.txt > fullmoon3.txt
	cat fullmoon3.txt | sed 's/Full/Full\n/g' > fullmoon4.txt
	cat fullmoon4.txt | sed 's/(E.*//g' > fullmoon5.txt
	awk '{print $1 " " $3 " " $4 " " $2 " at " $5}' fullmoon5.txt > fullmoon6.txt
	
	## Read full moon schedule
	cat fullmoon6.txt	
fi

	## Clean up files
	rm -f moon.txt
	rm -f fullmoon[0-9].txt
exit
