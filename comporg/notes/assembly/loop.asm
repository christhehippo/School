global _start

section .text
_start:
	mov rax, 1
top:
	cmp rax, 10 ;\	while (rax != 10)
	je  endloop ;/ {
	inc rax		; 	 rax++;
	jmp top		;  }
endloop:
	
bottom: 		;do {
	dec rax
	cmp rax, 0 ; \ } while (rax != 0)
	jnz bottom ; /


	mov rax, 60 ; fin
	mov rdi, 0
	syscall
