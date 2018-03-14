section .data
	number  db 	"  ", 0
;	sqrt    db 	 "2", 0
	testval db 	 "4", 0
	divisor db   "2", 0
;	arr     db  20 DUP(?)
section .text
	global _start

_start:
	mov rax, 0 ; Clear rax
	pop r8
	pop r9
	pop r10
	mov rax, 4 ; Value to be tested 
	mov rbx, 2 ; Value to divide
	mov rcx, testval

	
	


exit:
	mov rax, 60 ; 60 - sysexit system call
	mov rdi, 0
	syscall
