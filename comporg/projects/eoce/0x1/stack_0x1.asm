;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;  0x1, showing off stack
;;  give this two args, it will print
;; the name and first two args



section .data 
	name db "program name: ", 10
	arg1 db "  argv1: ", 10
	arg2 db "  argv2: ", 10
	nl   db " "
section .text
global _start

_start:

	pop r11     ; argc
	pop r8		; program name
	pop r9 		; argv[1]
	pop r10		; argv[2]

	mov r11, 5	; move 5 to register r11
	push r11    ; move to the top of the stack
	mov rax, 0
	mov rax, 1
	mov rsi, name  ; print "name"
	mov rdx, 0
	mov rdx, 13
	syscall
	
	mov rax, 0
	mov rax, 1
	mov rsi, r8
	mov rdx, 0
	mov rdx, 11
	syscall

	mov rax, 0
	mov rax, 1
	mov rsi, arg1  ; print argv1
	mov rdx, 0
	mov rdx, 9
	syscall
	
	mov rax, 0
	mov rax, 1
	mov rsi, r9
	mov rdx, 0
	mov rdx, 1
	syscall

	mov rax, 0
	mov rax, 1
	mov rsi, arg2 ; print argv2
	mov rdx, 0
	mov rdx, 9
	syscall
	
	mov rax, 0
	mov rax, 1
	mov rsi, r10
	mov rdx, 0
	mov rdx, 1
	syscall

	mov rax, 0
	mov rax, 1
	mov rsi, 0
	mov r8, 0
	add r8, 0xa
	mov [nl+0], r8
	mov rsi, nl
	mov rdx, 0
	mov rdx, 6
	syscall
	

.exit:
	
	mov rax, 60
	mov rdi, 0
	syscall
