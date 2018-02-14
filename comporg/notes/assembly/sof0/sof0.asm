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
	mov rdx, 1
	syscall

	; get the one's place value (copy byte from number "array" into register)
	;
	mov rax, 0
	mov al,  [number+1]
	sub al,  0x30
	cmp al,  0x5
	jne exit
	mul al,  0x5

	mov rbx, 0
	mov bl,  [number+0]
	sub bl,  0x30
	mov cl,  bl
	add cl,  1
	mul bl,  cl

	; itoa (convert integers back to ascii)
	;
	mov cl,  bl
	div cl,  10
	mov dl,  cl
	mul dl,  10 
	sub bl,  dl ; input 
	add bl,  0x30
	add cl,  0x30
	mov [output+0], cl
	mov [output+1], bl
	mov al,  5
	add al,  0x30
	mov bl,  2
	add bl , 0x30
	mov [output+2], bl
	mov [output+3], al
	mov dl,  0
	mov [output+4], dl

	; display answer (in output) to STDOUT via write syscall
	mov rax, 1
	mov rdi, 1 
	mov rsi, output
	mov rdx, 5
	syscall

	; return (0)
	;
exit:	
	mov rax, 60
	mov rdi, 0
	syscall
	
