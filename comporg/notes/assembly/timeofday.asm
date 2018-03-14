; NASM program to use the gettimeofday system call
; for fun and profit (and extreme pnc3 goodness)
;
section .bss
	mytime resb 8 ; struct timeval *tv

;section .data

global _start

section .text
_start:
	; gettimeofday(mytime,mytz);
	mov rax, 96 ; specify syscall #96 (gettimeofday)
	mov rdi, mytime
	mov rsi, 0
	syscall
	nop 
	nop

	; return (0);
	mov rax, 60
	mov rdi, 0
	syscall
