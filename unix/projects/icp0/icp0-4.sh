## icp0-4.sh | Christian Cattell | CSCS1730 ##
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

## BEGIN BODY

## START CIRCLE
xte 'sleep 1'
xwit -root -warp 1240 400 
xte 'mouseclick 1'
xte 'sleep 0.5'

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
	## Some calculations that will lead to x y coords
	RAD=`echo "$CIRCLE*($PI/180)" | bc -l`
	SIN=`echo "s($RAD)" | bc -l`
	COS=`echo "c($RAD)" | bc -l` 
	X=`echo "$COS*100" | bc -l`
	Y=`echo "$SIN*100" | bc -l`
	## Assign the X Y vars
	X=$(printf "%f" "$X" | cut -d . -f1)
	Y=$(printf "%f" "$Y" | cut -d . -f1)
	## Add the center point to values, not starting at 0,0
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
	
	CIRCLE=$(($CIRCLE+4))
done


xwit -root -warp 1285 120
xte 'mouseclick 1'
xte 'sleep 0.3'
xwit -root -warp 1240 310 
xte 'mouseclick 1'
xte 'sleep 0.3'
xwit -root -warp 1620 550
xte 'mouseclick 1'
xte 'sleep 0.2'
xwit -root -warp 1230 100
xte 'mouseclick 1'
xte 'sleep 0.2'

xwit -root -warp 1620 700 ##CENTER POINT

CIRCLE=0
PI=`echo "4*a(1)" | bc -l`
while [ $CIRCLE -le 360 ]
do
	## Reset X Y values
	X=0
	Y=0
	NEWX=0
	NEWY=0
	## Some calculations that will lead to x y coords
	RAD=`echo "$CIRCLE*($PI/180)" | bc -l`
	SIN=`echo "s($RAD)" | bc -l`
	COS=`echo "c($RAD)" | bc -l` 
	X=`echo "$COS*120" | bc -l`
	Y=`echo "$SIN*120" | bc -l`
	## Assign the X Y vars
	X=$(printf "%f" "$X" | cut -d . -f1)
	Y=$(printf "%f" "$Y" | cut -d . -f1)
	## Add the center point to values, not starting at 0,0
	NEWX=$(($X+1620))
	NEWY=$(($Y+700))
	
	xwit -root -warp ${NEWX} ${NEWY}
	
	if [ $CIRCLE = 0 ]
	then
		xte 'mousedown 1'
	fi

	if [ $CIRCLE = 360 ]
	then
		xte 'mouseup 1'
	fi
	
	CIRCLE=$(($CIRCLE+4))
done

xwit -root -warp 1285 120
xte 'mouseclick 1'
xte 'sleep 0.3'
xwit -root -warp 1240 310 
xte 'mouseclick 1'
xte 'sleep 0.3'
xwit -root -warp 1620 700 
xte 'mouseclick 1'
xte 'sleep 0.2'
xwit -root -warp 1230 100
xte 'mouseclick 1'
xte 'sleep 0.2'

## TWO WHITE CIRLCES DONE
## BUTTONS
xwit -root -warp 1240 405 
xte 'mouseclick 1'
xte 'sleep 0.3'

xwit -root -warp 1620 700 ##CENTER POINT

CIRCLE=0
PI=`echo "4*a(1)" | bc -l`
while [ $CIRCLE -le 360 ]
do
	## Reset X Y values
	X=0
	Y=0
	NEWX=0
	NEWY=0
	## Some calculations that will lead to x y coords
	RAD=`echo "$CIRCLE*($PI/180)" | bc -l`
	SIN=`echo "s($RAD)" | bc -l`
	COS=`echo "c($RAD)" | bc -l` 
	X=`echo "$COS*10" | bc -l`
	Y=`echo "$SIN*10" | bc -l`
	## Assign the X Y vars
	X=$(printf "%f" "$X" | cut -d . -f1)
	Y=$(printf "%f" "$Y" | cut -d . -f1)
	## Add the center point to values, not starting at 0,0
	NEWX=$(($X+1620))
	NEWY=$(($Y+700))
	
	xwit -root -warp ${NEWX} ${NEWY}
	
	if [ $CIRCLE = 0 ]
	then
		xte 'mousedown 1'
	fi

	if [ $CIRCLE = 360 ]
	then
		xte 'mouseup 1'
	fi
	
	CIRCLE=$(($CIRCLE+4))
done

xwit -root -warp 1285 120
xte 'mouseclick 1'
xte 'sleep 0.3'
xwit -root -warp 1620 700 
xte 'mouseclick 1'
xte 'sleep 0.2'
xwit -root -warp 1230 100
xte 'mouseclick 1'
xte 'sleep 0.2'


xwit -root -warp 1620 730 ##CENTER POINT

CIRCLE=0
PI=`echo "4*a(1)" | bc -l`
while [ $CIRCLE -le 360 ]
do
	## Reset X Y values
	X=0
	Y=0
	NEWX=0
	NEWY=0
	## Some calculations that will lead to x y coords
	RAD=`echo "$CIRCLE*($PI/180)" | bc -l`
	SIN=`echo "s($RAD)" | bc -l`
	COS=`echo "c($RAD)" | bc -l` 
	X=`echo "$COS*10" | bc -l`
	Y=`echo "$SIN*10" | bc -l`
	## Assign the X Y vars
	X=$(printf "%f" "$X" | cut -d . -f1)
	Y=$(printf "%f" "$Y" | cut -d . -f1)
	## Add the center point to values, not starting at 0,0
	NEWX=$(($X+1620))
	NEWY=$(($Y+730))
	
	xwit -root -warp ${NEWX} ${NEWY}
	
	if [ $CIRCLE = 0 ]
	then
		xte 'mousedown 1'
	fi

	if [ $CIRCLE = 360 ]
	then
		xte 'mouseup 1'
	fi
	
	CIRCLE=$(($CIRCLE+4))
done

xwit -root -warp 1285 120
xte 'mouseclick 1'
xte 'sleep 0.3'
xwit -root -warp 1620 730 
xte 'mouseclick 1'
xte 'sleep 0.2'
xwit -root -warp 1230 100
xte 'mouseclick 1'
xte 'sleep 0.2'


xwit -root -warp 1620 760 ##CENTER POINT

CIRCLE=0
PI=`echo "4*a(1)" | bc -l`
while [ $CIRCLE -le 360 ]
do
	## Reset X Y values
	X=0
	Y=0
	NEWX=0
	NEWY=0
	## Some calculations that will lead to x y coords
	RAD=`echo "$CIRCLE*($PI/180)" | bc -l`
	SIN=`echo "s($RAD)" | bc -l`
	COS=`echo "c($RAD)" | bc -l` 
	X=`echo "$COS*10" | bc -l`
	Y=`echo "$SIN*10" | bc -l`
	## Assign the X Y vars
	X=$(printf "%f" "$X" | cut -d . -f1)
	Y=$(printf "%f" "$Y" | cut -d . -f1)
	## Add the center point to values, not starting at 0,0
	NEWX=$(($X+1620))
	NEWY=$(($Y+760))
	
	xwit -root -warp ${NEWX} ${NEWY}
	
	if [ $CIRCLE = 0 ]
	then
		xte 'mousedown 1'
	fi

	if [ $CIRCLE = 360 ]
	then
		xte 'mouseup 1'
	fi
	
	CIRCLE=$(($CIRCLE+4))
done

xwit -root -warp 1285 120
xte 'mouseclick 1'
xte 'sleep 0.3'
xwit -root -warp 1620 760 
xte 'mouseclick 1'
xte 'sleep 0.2'
xwit -root -warp 1230 100
xte 'mouseclick 1'
xte 'sleep 0.2'

## DONE WITH BUTTONS
## EYES

xwit -root -warp 1570 500 ##CENTER POINT

CIRCLE=0
PI=`echo "4*a(1)" | bc -l`
while [ $CIRCLE -le 360 ]
do
	## Reset X Y values
	X=0
	Y=0
	NEWX=0
	NEWY=0
	## Some calculations that will lead to x y coords
	RAD=`echo "$CIRCLE*($PI/180)" | bc -l`
	SIN=`echo "s($RAD)" | bc -l`
	COS=`echo "c($RAD)" | bc -l` 
	X=`echo "$COS*10" | bc -l`
	Y=`echo "$SIN*10" | bc -l`
	## Assign the X Y vars
	X=$(printf "%f" "$X" | cut -d . -f1)
	Y=$(printf "%f" "$Y" | cut -d . -f1)
	## Add the center point to values, not starting at 0,0
	NEWX=$(($X+1570))
	NEWY=$(($Y+500))
	
	xwit -root -warp ${NEWX} ${NEWY}
	
	if [ $CIRCLE = 0 ]
	then
		xte 'mousedown 1'
	fi

	if [ $CIRCLE = 360 ]
	then
		xte 'mouseup 1'
	fi
	
	CIRCLE=$(($CIRCLE+4))
done

xwit -root -warp 1285 120
xte 'mouseclick 1'
xte 'sleep 0.3'
xwit -root -warp 1570 500 
xte 'mouseclick 1'
xte 'sleep 0.2'
xwit -root -warp 1230 100
xte 'mouseclick 1'
xte 'sleep 0.2'

## EYE 2

xwit -root -warp 1670 500 ##CENTER POINT

CIRCLE=0
PI=`echo "4*a(1)" | bc -l`
while [ $CIRCLE -le 360 ]
do
	## Reset X Y values
	X=0
	Y=0
	NEWX=0
	NEWY=0
	## Some calculations that will lead to x y coords
	RAD=`echo "$CIRCLE*($PI/180)" | bc -l`
	SIN=`echo "s($RAD)" | bc -l`
	COS=`echo "c($RAD)" | bc -l` 
	X=`echo "$COS*10" | bc -l`
	Y=`echo "$SIN*10" | bc -l`
	## Assign the X Y vars
	X=$(printf "%f" "$X" | cut -d . -f1)
	Y=$(printf "%f" "$Y" | cut -d . -f1)
	## Add the center point to values, not starting at 0,0
	NEWX=$(($X+1670))
	NEWY=$(($Y+500))
	
	xwit -root -warp ${NEWX} ${NEWY}
	
	if [ $CIRCLE = 0 ]
	then
		xte 'mousedown 1'
	fi

	if [ $CIRCLE = 360 ]
	then
		xte 'mouseup 1'
	fi
	
	CIRCLE=$(($CIRCLE+4))
done

xwit -root -warp 1285 120
xte 'mouseclick 1'
xte 'sleep 0.3'
xwit -root -warp 1670 500 
xte 'mouseclick 1'
xte 'sleep 0.2'
xwit -root -warp 1230 100
xte 'mouseclick 1'
xte 'sleep 0.2'

## TRiANGLE 1620 550 is center of head
## TRIANGLE IS NOSE

TRI1A=1600
TRI1B=550

xwit -root -warp 1240 430
xte 'sleep 0.3'
xte 'mouseclick 1'

xte 'sleep 0.3'
xwit -root -warp 1600 550
xte 'mousedown 1'
xte 'sleep 0.2'

while [ $TRI1A -le 1620 ]
do
	xwit -root -warp ${TRI1A} ${TRI1B}

	TRI1A=$(($TRI1A+1))
	TRI1B=$(($TRI1B+2))
done
xte 'sleep 0.2'
xte 'mouseup 1'

TRI1C=1620
TRI1D=590


xte 'sleep 0.3'
xte 'mousedown 1'
xte 'sleep 0.2'

while [ $TRI1C -le 1640 ]
do
	xwit -root -warp ${TRI1C} ${TRI1D}

	TRI1C=$(($TRI1C+1))
	TRI1D=$(($TRI1D-2))

done
xte 'sleep 0.2'
xte 'mouseup 1'
xte 'sleep 0.2'
xte 'mousedown 1'

TRI1E=1640

while [ $TRI1E -ge 1600 ]
do
	xwit -root -warp ${TRI1E} 550

	TRI1E=$(($TRI1E-1))

done
xte 'sleep 0.2'
xte 'mouseup 1'
xte 'sleep 0.2'

xwit -root -warp 1285 120
xte 'mouseclick 1'
xte 'sleep 0.2'
xwit -root -warp 1620 560
xte 'sleep 0.2'
xte 'mouseclick 1'
xwit -root -warp 1230 100
xte 'mouseclick 1'
xte 'sleep 0.2'

xwit -root -warp 1290 220 
xte 'sleep 0.2'
xte 'mousedown 1'
xte 'sleep 0.1'
xwit -root -warp 1290 270
xte 'sleep 0.2'
xte 'mouseup 1'
xte 'sleep 0.1'
xwit -root -warp 1250 825
xte 'sleep 0.1'
xte 'mouseclick 1'
xte 'sleep 0.1'
## NOSE DONE

##ARMS
xwit -root -warp 1560 710
xte 'sleep 0.1'

ARM1A=1560
xte 'mousedown 1'
## First loop for left arm
while [ $ARM1A -ge 1440 ]
do
	xwit -root -warp ${ARM1A} 710
	ARM1A=$(($ARM1A-2))
done

ARM1B=710
## Next loop for left arm
while [ $ARM1B -le 750 ]
do
	xwit -root -warp 1440 ${ARM1B}
	ARM1B=$(($ARM1B+1))
done

ARM1C=1440
## Third loop for left arm
while [ $ARM1C -le 1560 ]
do
	xwit -root -warp ${ARM1C} 750
	ARM1C=$(($ARM1C+2))
done

ARM1D=750
## Next loop for left arm
while [ $ARM1D -ge 710 ]
do
	xwit -root -warp 1560 ${ARM1D}
	ARM1D=$(($ARM1D-1))
done

xte 'sleep 0.1'
xte 'mouseup 1'


