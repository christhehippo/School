.arm

.global _start

_start:
.text

	mov r1, #1  // 1 to r1
	mov r2, #2  // 2 to r2

	push {r1}   // 1 to stack
	push {r2}	// 2 to stack

	pop {r1}	// 2 to r1
	pop {r2}    // 1 to r2


	mov r7, #1  // exit
	mov r0, #0
	swi 0

