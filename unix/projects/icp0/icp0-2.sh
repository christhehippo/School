## icp0-2.sh | Christian Cattell | CSCS1730 ##
##############################################
#
#!/bin/bash

## Bring window to focus
xwit -focus

## Open mtpaint 
mtpaint& 
xte 'sleep 2'
## Move mtpaint window to right moniter
	## Isolate mtpaint window id
xwit -print -all > xwit_info.txt
grep 'mtPaint 3.40' xwit_info.txt | sed 's/ /:/g' | cut -d : -f1 > mtPaint_id.txt
	## Now move
MTPAINT=$(cat mtPaint_id.txt)
xwit -id $MTPAINT -move 1200 0	

## Click pencil
xwit -root -warp 1230 100
xte 'mouseclick 1'
xte 'sleep 0.5'

## Each shape has a loop for each side, so total 8 loops
## Lack of comments there because they are basically the same
## Start first square - red
xwit -root -warp 1400 350
xte 'mousedown 1'

LOOP1_A=1400

while [ $LOOP1_A -lt 1900 ]
do
	LOOP1_A=$(($LOOP1_A+5))

	xwit -root -warp ${LOOP1_A} 350

done

xte 'mouseup 1'
xte 'sleep 0.5'
xte 'mousedown 1'

LOOP2_A=350

while [ $LOOP2_A -lt 750 ]
do
	LOOP2_A=$(($LOOP2_A+5))

	xwit -root -warp 1900 ${LOOP2_A} 

done

xte 'mouseup 1'
xte 'sleep 0.5'
xte 'mousedown 1'

LOOP3_A=1900

while [ $LOOP1_A -gt 1400 ]
do
	LOOP1_A=$(($LOOP1_A-5))

	xwit -root -warp ${LOOP1_A} 750

done

xte 'mouseup 1'
xte 'sleep 0.5'
xte 'mousedown 1'

LOOP4_A=750

while [ $LOOP4_A -gt 350 ]
do
	LOOP4_A=$(($LOOP4_A-5))

	xwit -root -warp 1400 ${LOOP4_A} 

done

xte 'mouseup 1'
xte 'sleep 0.5'

## NEW COLOR
xwit -root -warp 1250 269
xte 'sleep 0.2'
xte 'mouseclick 1'
xte 'sleep 0.2'

## Start second square - blue
xwit -root -warp 1600 450
xte 'mousedown 1'

LOOP1_B=1600

while [ $LOOP1_B -lt 1800 ]
do
	LOOP1_B=$(($LOOP1_B+5))

	xwit -root -warp ${LOOP1_B} 450

done

xte 'mouseup 1'
xte 'sleep 0.5'
xte 'mousedown 1'

LOOP2_B=450

while [ $LOOP2_B -lt 700 ]
do
	LOOP2_B=$(($LOOP2_B+5))

	xwit -root -warp 1800 ${LOOP2_B} 

done

xte 'mouseup 1'
xte 'sleep 0.5'
xte 'mousedown 1'

LOOP3_B=1800

while [ $LOOP1_B -gt 1600 ]
do
	LOOP1_B=$(($LOOP1_B-5))

	xwit -root -warp ${LOOP1_B} 700

done

xte 'mouseup 1'
xte 'sleep 0.5'
xte 'mousedown 1'

LOOP4_B=700

while [ $LOOP4_B -gt 450 ]
do
	LOOP4_B=$(($LOOP4_B-5))

	xwit -root -warp 1600 ${LOOP4_B} 

done

xte 'mouseup 1'
xte 'sleep 0.5'


