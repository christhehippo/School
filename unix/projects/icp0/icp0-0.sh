## icp0-0.sh | Christian Cattell | CSCS1730 ##
##############################################
#
#!/bin/bash

## Bring window to focus
xwit -focus

## Bring window to 'center' of left moniter
xwit -move 250 400

## Mouse move command
xte "mousemove 250 400"
xte "sleep 0.5"
xte "mousemove 250 400"
xte "sleep 0.5"
xte "mousemove 250 400"
xte "sleep 0.5"
xte "mousemove 250 400"
xte "sleep 0.5"
#
## Mouse click command
xte "mouseclick 1"
xte "sleep 0.5"
xte "mouseclick 1"

exit
