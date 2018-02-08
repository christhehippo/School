section .data
	inputmsg db "Enter number: "
	junk 	 db " ", 0
	number   db "  ", 0
	output   db "     "

section .text
	global _start

_start:
	; prompt user to enter a number
	; using write syscall (1 in rax)
	;
	mov rax, 1 
	mov rdi, 1
	mov rsi, inputmsg
	mov rdx, 14
	syscall

	; obtain input from user
	; using read syscal (stdin)
	;
	mov rax, 0
	mov rdi, 0
	mov rsi, number
	mov rdx, 2
	syscall

	; get rid of the newline
	;
	mov rax, 0
	mov rdi, 0
	mov rsi, junk
	mov rdx,  1
	syscall
	
	; return (0)
	;
	mov rax, 60
	mov rdi, 0
	syscall
	
