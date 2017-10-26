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
xwininfo > xwininfo.txt
xte 'sleep 0.1'
xte 'mouseclick 1'
cat xwininfo.txt | head -13 | tail -2 | cut -d ' ' -f4 > windowWH

## Assign width and height variables 
WIDTH=$(cat windowWH | head -1)
HEIGHT=$(cat windowWH | tail -1)

## Move mouse in arbitrary lines

LINEONE=$(($WIDTH/2)-1)
LINEONELOOP=5

while [ $LINEONELOOP -lt $LINEONE ]
  do 
  	xte 'mousemove (250+$LINEONELOOP) 400'
	xte 'sleep 0.01'
	$LINEONELOOP=$LINEONELOOP+5

done 

LINETWO=$(($HEIGHT/2)-1)
LINETWOLOOP=5

while [ $LINETWOLOOP -lt $LINETWO ]
  do 
  	xte 'mousemove 250 (400+$LINETWOLOOP)'
	xte 'sleep 0.01'
	$LINETWOLOOP=$LINETWOLOOP+5

done







