## icp0-1.sh | Christian Cattell | CSCS1730 ##
##############################################
#
#!/bin/bash

## Bring window to focus
xwit -focus

## Resize window
##xwit -resize 1002 1241

## Bring window to 'center' of left moniter
xwit -move 250 400

xte 'mousemove 250 400'
xte 'sleep 0.25'
xte 'mouseclick 1'

## Place window info in a text file
##xwininfo -name pod21 > xwininfo.txt
xte 'sleep 0.5'
xte 'mouseclick 1'
xte 'sleep 0.5'
cat xwininfo.txt | head -9 | tail -2 | cut -d ' ' -f4 > windowWH

## Assign width and height variables 
WIDTH=$(cat windowWH | head -1)
HEIGHT=$(cat windowWH | tail -1)

LOOP1=401
LINEONEPOINT=600

while [ $LOOP1 -le $LINEONEPOINT ]
do
	xwit -root warp ${LOOP1} 600

	LOOP1=$(($LOOP1+1))
done
LOOP2=600
LOOP2EXTRA=600
LINETWOPOINT=900
while [ $LOOP2 -le $LINETWOPOINT ]
do
	xwit -root warp ${LOOP2} ${LOOP2EXTRA}

	LOOP2=$(($LOOP2+1))
	LOOP2EXTRA=$(($LOOP2EXTRA+2))

done

LOOP3_1=900
LOOP3_2=1200
while [ $LOOP3_2 -gt 0 ]
do
	xwit -root warp  ${LOOP3_1} ${LOOP3_2}

	LOOP3_1=$(($LOOP3_1-1))
	LOOP3_2=$(($LOOP3_2-1))

done

LOOP4_1=0
LOOP4_2=0

while [ $LOOP4_1 -le 2048 ]
do
	xwit -root warp ${LOOP4_1} ${LOOP4_2}
	
	LOOP4_1=$(($LOOP4_1+2))

done

LOOP5_1=2048
LOOP5_2=0

while [ $LOOP5_2 -le 1280 ]
do
	xwit -root warp ${LOOP5_1} ${LOOP5_2}
	
	LOOP5_2=$(($LOOP5_2+2))

done


LOOP6_1=2048
LOOP6_2=1280

while [ $LOOP6_1 -ge 0 ]
do
	xwit -root warp ${LOOP6_1} ${LOOP6_2}
	
	LOOP6_1=$(($LOOP6_1-2))

done


