.arm

.global _start

_start:
.text

	// atoi
	pop	{r8}		// argc
	pop {r8} 		// argv[0] - program name
	pop {r8}		// argv[1] - first arg
	ldr  r0, [r8]	// load contents of r8 to r0

	// timer






	// r1 test value
	mov r1, #3
	
	// r2 divisor 
	mov r2, #2

	//

























.exit:
	mov r7, #1	// exit
	mov r0, #0
	swi 0
