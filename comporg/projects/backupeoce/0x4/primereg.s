.arm

.global _start

_start:
.text

	// atoi
	pop	{r0}		// argc
	pop {r0} 		// argv[0] - program name
	pop {r0}		// argv[1] - first arg

	ldrb r1, [r0, #0]	// load contents of r8 to r0
	mov  r7, #48
	sub  r1, r7			// ascii the first digit

	ldrb r2, [r0, #1]   // load the second byte
	mov  r8, #0
	cmp  r2, r8			// check for \0
	beq .next

	sub  r2, r7 
	mov  r7, #10
	mul  r1, r7			// move tens place
	add  r1, r2			// combine numbers

	ldrb r3, [r0, #2]
	cmp  r3, r8
	beq .next

	mov  r7, #48
	sub  r3, r7
	mov  r7, #10
	mul  r1, r7
	add  r1, r3

	ldrb r4, [r0, #3]
	cmp  r4, r8
	beq .next

	mov  r7, #48
	sub  r4, r7
	mov  r7, #10
	mul  r1, r7
	add  r1, r4

	ldrb r5, [r0, #4]
	cmp  r5, r8
	beq .next 

	mov  r7, #48
	sub  r5, r7
	mov  r7, #10
	mul  r1, r7
	add  r1, r5
	// stop checking after 5 digits

.next:
	// r12 contains number of primes to calculate
	mov  r12, r1	// free up r1 for syscalls
	mov  r2, #2		// value that will be tested
	mov  r3, #2		// divisor for second loop
	mov  r4, #0     // r4 will be used to store prime flag
	                // if r4 == 1, number is not prime
	mov  r5, r2     // r5 is a backup of test number
	mov  r6, #1     // r6 holds 1 used to inc numbers
	mov  r8, #1     // r8 holds the count of prime numbers

.printatwo:
	mov  r11, #50
	ldr  r10, =one	// get the address of the string
	str  r11, [r10, #0] // store r11 into position 0
	mov  r2, #32
	str  r2, [r10, #1]  // store a space into position 1

	mov  r0, #2
	ldr  r1, =one
	mov  r2, #2
	mov  r7, #4		// print it 
	swi  0
.timerstart:
	ldr  r0, =start
	mov  r1, #0
	mov  r7, #0x4e
	swi  0 

.primecheck:
	cmp  r4, r6		// stop and see if we need to print the number before
	beq .print		//  upping it
	mov  r4, #1

.reset:
	add  r5, r6		// up the test number
	mov  r2, r5		// replace the test value
	mov  r3, #2		// reset the divisor

.divide:
	sdiv r2, r3     // divide test number by divisor
	mul  r2, r3     // multiply the quo by the original divisor	
	cmp  r5, r2		// compare the new value with the original value
	beq .notprime
	mov  r2, r5		// replace the test value
	add  r3, r6     // inc the divisor
	cmp  r3, r2
	beq .primecheck	// if we reached the limit, reset
	b   .divide		// if not, go back to .dive
.notprime:
	mov  r4, #0
	mov  r2, r5		// replace the test value
	add  r3, r6		// inc the divisor
	cmp  r3, r2
	beq .primecheck	// check if we done
	b   .divide		// if not, keep dividing
		
.print:
	mov  r11, r5	// store ascii char here
	mov  r9, #9		// r9 holds whatever temp value is needed
	cmp  r5, r9
	bgt .twod
	mov  r9, #48
	add  r11, r9	// asciificate
	ldr  r10, =one	// get the address of the string
	str  r11, [r10, #0] // store r11 into position 0
	mov  r2, #32
	str  r2, [r10, #1]  // store a space into position 1

	mov  r0, #2
	ldr  r1, =one
	mov  r2, #2
	mov  r7, #4		// print it 
	swi  0
	b   .doneprinting

.twod:
	mov  r9, #99
	cmp  r5, r9
	bgt .threed
	mov  r11, r5
	mov  r2, #10	// 10 to isolate tens place
	udiv r11, r2	// get 10s place
	mov  r3, r11	// copy it
	mul  r3, r2	    // multiply it by 10 to isolate ones place
	mov  r9, r5		// get another copy of the original number
	sub  r9, r3
	mov  r3, #48	// store 48 for asciing
	add  r9, r3 	// ones place
	add  r11, r3	// tens place
	ldr  r10, =two
	str  r11, [r10, #0]
	str  r9, [r10, #1]
	mov  r9, #32
	str  r9, [r10, #2]

	mov  r0, #2
	ldr  r1, =two
	mov  r2, #3
	mov  r7, #4		// print it 
	swi  0
	b   .doneprinting

.threed:
	mov  r9, #999
	cmp  r5, r9
	bgt .fourd
	mov  r11, r5		// backup 1 of test number
	mov  r2, #100
	udiv r11, r2		// get the hundreds place
	mov  r2, r11		// save that number
	ldr  r10, =three
	mov  r3, #48
	add  r2, r3
	str  r2, [r10, #0]	// captured hundreds place
	mov  r2, r5			// get another copy of original number
	mov  r3, #100
	mul  r11, r3		// get the prior saved hundreds place, mul by 100
	sub  r2, r11		// now we have the tens and ones in r2
	mov  r9, r2			// save a copy somewhere it doesnt even matter anymore
	mov  r3, #10
	udiv  r2, r3			// r2 now holds tens place 
	mov  r3, #48
	add  r2, r3
	str  r2, [r10, #1]	// store the tens place
	sub  r2, r3			// un ascii it
	mov  r3, #10
	mul  r2, r3
	sub  r9, r2			// heres the ones place 
	mov  r3, #48
	add  r9, r3
	str  r9, [r10, #2]
	mov  r3, #32
	str  r3, [r10, #3]

	mov  r0, #2
	ldr  r1, =three
	mov  r2, #4
	mov  r7, #4		// print it 
	swi  0
	b   .doneprinting

.fourd:
	mov  r9, #9999
	cmp  r5, r9
	bgt .fived
	
	mov  r11, r5		// back er up
	mov  r9, #1000
	udiv r11, r9		// r11 now holds the thous place
	mov  r2, r11		// copy it for later
	mov  r3, #48
	add  r2, r3
	ldr  r10, =four
	str  r2, [r10, #0]
	mov  r11, r5
	sub  r2, r3			// undo the ascii
	mul  r2, r9			// get isolated thousands value
	sub  r11, r2		// r11 is now the hundreds value
	mov  r2, r11    	// copy it
	mov  r9, #100	
	
	udiv r2, r9			// r2 is now the hundres place
	add  r2, r3			// ascii it
	str  r2, [r10, #1]
	sub  r2, r3
	mul  r2, r9			// now we have isolated hundreds value
	sub  r11, r2         // heres the tens stuff
	mov  r2, r11		// save it
	mov  r9, #10
	udiv r2, r9
	add  r2, r3			// make it ascii
	str  r2, [r10, #2]
	sub  r2, r3
	mul  r2, r9	
	sub  r11, r2		// now r11 is the ones place value
	add  r11, r3		// ascii the ones place
	str  r11, [r10, #3]
	mov  r11, #32
	str  r11, [r10, #4]
	
	mov  r0, #2
	ldr  r1, =four
	mov  r2, #5
	mov  r7, #4		// print it 
	swi  0
	b   .doneprinting


.fived:
	mov  r11, r5		// get print value
	mov  r9, #10000
	udiv  r11, r9		// ten thous place in r11
	mov  r2, r11		// make copy
	mov  r3, #48
	add  r2, r3
	ldr  r10, =five
	str  r2, [r10, #0]
	sub  r2, r3			// now get the thous place
	mov	 r11, r5
	mul  r2, r9
	sub  r11, r2
	mov  r2, r11		// back it up
	mov  r9, #1000
	udiv  r2, r9
	add  r2, r3
	str  r2, [r10, #1]
	sub  r2, r3
	mul  r2, r9
	sub  r11, r2
	mov  r2, r11
	mov  r9, #100
	udiv  r2, r9
	add  r2, r3
	str  r2, [r10, #2]
	sub  r2, r3
	mul	 r2, r9
	sub  r11, r2
	mov  r2, r11		// the print algorithm really clicked on 5 digit numbers
	mov  r9, #10
	udiv r2, r9
	add  r2, r3
	str  r2, [r10, #3]
	sub  r2, r3
	mul  r2, r9
	sub  r11, r2
	add  r11, r3
	str  r11, [r10, #4]
	mov  r2, #32
	str  r2, [r10, #5]

	mov  r0, #2
	ldr  r1, =five
	mov  r2, #6
	mov  r7, #4		// print it 
	swi  0
	b   .doneprinting


.doneprinting:	
	add  r8, r6
	cmp  r8, r12	// see if quota was reached
	bne .reset

.exit:
	ldr  r0, =end
	mov  r1, #0
	mov  r7, #0xd
	swi  0 
	
	ldr  r0, =end
	ldr  r1, =start
	sub  r0, r1


	mov  r0, #1
	ldr  r1, =nl
	mov  r3, #10
	str  r3, [r1, #0]
	mov  r2, #2
	mov  r7, #4
    swi  0 
	
	mov  r7, #1	// exit
	mov  r0, #0
	swi  0



.data
	one:   .asciz "  "
	two:   .asciz "   "
	three: .asciz "    "
	four:  .asciz "     "
	five:  .asciz "      "
	nl:    .asciz ""
	start: .word 0
	end:   .word 0
