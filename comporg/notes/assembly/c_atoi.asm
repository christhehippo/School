; assembly program that calls upon the C library's atoi() function
; to assemble: nasm -f elf64 -o c_atoi.o c_atoi.asm
; to link:     gcc -nostartfiles -o c_atoi c_atoi.o
;
extern atoi
extern puts

global _start
section .data
	mystring db "47", 0
;	thing: $-mystring

section .text
_start:
	push rbp
	mov rdi, mystring
;	push rax
	call puts wrt ..plt
	pop rbp

	mov rax, 60
	mov rsi, 0
	syscall
;	mov rax, 0
;	push rax
;	call exit
