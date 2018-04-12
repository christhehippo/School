.arm

.global _start

_start:
.text
	nop
	pop {r0}
	pop {r1}
	pop {r3}
	pop {r4}
	pop {r5}
	pop {r6}
	nop
	nop
	nop
	mov r7, #4   // placing immediate value of 4 into register r7
				 // 4 is sys_write on ARM32

	mov r0, #1	 // file descriptor (1 is STDOUT)
//	mov r2, #14  // number of bytes to operate on (to write, being sys_write)
	ldr r8, =len // load address of len in r8 (hopefully an unused register)
	mov r2, %r8  // dereference value at memory address, move it into r2
	ldr r1, =msg // load address of msg into r1
	swi 0 		 // perform/activate system call

	mov r7, #1	 // sys _exit
	mov r0, #0
	swi 0

.data 
	msg: 	.asciz "Hello, World!\n"
	len = . - msg

