## icp0-3.sh | Christian Cattell | CSCS1730 ##
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
grep 'mtPaint 3.40' xwit_info.txt | sed 's/ /:/g' | cut -d ':' -f1 > mtPaint_id.txt
	## Now move
MTPAINT=$(cat mtPaint_id.txt)
xwit -id $MTPAINT -move 1200 0	

## Click pencil
xwit -root -warp 1230 100
xte 'mouseclick 1'
xte 'sleep 0.5'

## START CIRCLE

xwit -root -warp 1620 550 ##CENTER POINT

CIRCLE=0
PI=`echo "4*a(1)" | bc -l`
while [ $CIRCLE -le 360 ]
do
	## Reset X Y values
	X=0
	Y=0
	NEWX=0
	NEWY=0

	RAD=`echo "$CIRCLE*($PI/180)" | bc -l`
	SIN=`echo "s($RAD)" | bc -l`
	COS=`echo "c($RAD)" | bc -l` 
	X=`echo "$COS*100" | bc -l`
	Y=`echo "$SIN*100" | bc -l`
	
##	printf "ANGLE: %d  " "$CIRCLE"
	X=$(printf "%f" "$X" | cut -d . -f1)
	Y=$(printf "%f" "$Y" | cut -d . -f1)

	NEWX=$(($X+1620))
	NEWY=$(($Y+550))
	
	xwit -root -warp ${NEWX} ${NEWY}
	
	if [ $CIRCLE = 0 ]
	then
		xte 'mousedown 1'
	fi

	if [ $CIRCLE = 360 ]
	then
		xte 'mouseup 1'
	fi
	
	CIRCLE=$(($CIRCLE+1))
done


xwit -root -warp 1285 120
xte 'mouseclick 1'
xte 'sleep 0.3'
xwit -root -warp 1240 520
xte 'mouseclick 1'
xte 'sleep 0.3'
xwit -root -warp 1620 550
xte 'mouseclick 1'




