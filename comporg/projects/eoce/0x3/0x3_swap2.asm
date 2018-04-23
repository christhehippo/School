global _start

section .text
_start:


	mov r8, 8
	mov r9, 9

	XCHG r8, r9 

	mov rax, 60
	mov rdi, 0
	syscall

