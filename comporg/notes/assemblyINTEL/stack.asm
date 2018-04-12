global _start

section .bss
	mystack resb 100

section .text
_start:
	mov rax, 1
	push rax

	mov rax, 2
	push rax

	 
	mov r10, rsp ; save stack pointer into data register r10
	mov rsp, mystack ; load ourstack's address into rsp (top)


	mov rax, 3
	push rax
	
	mov rax, 4
	push rax
	
	mov r11, rsp ; save stack pointer into data register r10
	mov rsp, r10 ; load ourstack's original address into rsp (top)

	pop rbx	
	pop rbx
	pop rbx

	mov r10, rsp ; load ourstack's original address into rsp (top)
	mov rsp, r11 ; save stack pointer into data register r10

	pop rbx
	pop rbx

	; Exit
	mov rax, 60
	mov rdi, 0
	syscall
	
