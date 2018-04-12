; NASM program to use the gettimeofday system call
; for fun and profit (and extreme pnc3 goodness)
;
section .bss
	mytime  resb 16  ; struct timeval *tv
	mytime2 resb 16  ; struct timeval *tv
	mydelay resb 16  

section .data
;	mydelay db 0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0

global _start

section .text
_start:
	; gettimeofday(mytime,mytz);
	mov rax, 96 ; specify syscall #96 (gettimeofday)
	mov rdi, mytime
	mov rsi, 0
	syscall
	
	mov rbx, 0
	mov rcx, 11
	mov rax, mydelay
;	mov [rax], rbx
;	inc rax
;	mov [rax], rbx
;	inc rax
;	mov [rax], rbx
;	inc rax
;	mov [rax], rbx
;	inc rax
	mov [rax], rcx
	inc rax
	mov [rax], rbx
	inc rax
	mov [rax], rbx
	inc rax
	mov [rax], rbx

	
	nop 
	; sys_nanosleep (syscall 35, struct timespec *, 0)
	mov rax, 35 ; specify syscall #96 (gettimeofday)
	mov rdi, mydelay
	mov rsi, 0
	syscall
	nop 
	

	; gettimeofday(mytime,mytz);
	mov rax, 96 ; specify syscall #96 (gettimeofday)
	mov rdi, mytime2
	mov rsi, 0
	syscall
	

	mov rbx, [mytime]
	mov rax, [mytime2]
	sub rax, rbx
	mov rcx, rax 		; rcx will contain our seconds

	
	mov rbx, [mytime+8]
	mov rax, [mytime2+8]
	sub rax, rbx

	; return (0);
	mov rax, 60
	mov rdi, 0
	syscall
