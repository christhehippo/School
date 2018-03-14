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
	mov bl,  5
	mul bl
	mov r8, rax ; saveour integer 25 into r8

	; get the tens place value
	;
	mov rax, 0
	mov al,  [number+0]
	sub al,  0x30
	mov bl,  al
	add bl,  1
	mul bl
	mov r9,  rax ; save our integer into r9

	; itoa (convert integers back to ascii)
	;
	mov bl,  10
	div bl
	mov cl, ah  		; copy remainder into c register
	and ax,  0x00FF 	; preserve just the quotient
	add al,  0x30   	; ASCII-ify our integer value
	mov [output+0], al  ; place it in our memory

	add cl, 0x30		; ASCII-fy our remainder value
	mov [output+1], cl  ; place it in our memory

	mov rax, r8			; copy 25 into A register
	mov bl,  10			; set up for division
	div bl				; divide
	mov cl,  ah			; save remainder (5)
	and ax,  0x00FF		; mask it
	add al,  0x30		; ASCII-ify the 2
	mov [output+2], al  ; store it 

	add cl,  0x30		; ASCII-ify 5
	mov [output+3], cl	; store itl

	mov rax, 10			; place a 10 (ASCII newline) in A reg
	mov [output+4], al	; pad newline onto our ASCII string

	; display answer (in output) to STDOUT via write syscall
	;
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


