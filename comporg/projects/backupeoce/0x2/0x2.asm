section .data
	newline db " "
	one     db "  "
	two     db "   "
	three   db "    "

section .text
global _start

_start:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; atoi do 
.atoi0:
	pop r11		; argc
	pop r11		; argv[0]
	pop r11		; argv[1] - value number 1
	mov rax, 0

.atoi1:
	mov rcx, 10 ; mul by 10 for place
	mul rcx
	movzx rbx, byte[r11]
	inc r11
	mov rcx, 0
	cmp rbx, rcx
	je .next0
	mov rcx, 0x30
	sub rbx, rcx
	add rax, rbx
	jmp .atoi1

.next0:
	mov rcx, 10	; extra 0 needs to be dropped
	div rcx
	mov r12, rax

.atoi2:
	mov r11, 0
	pop r11
	mov rax, 0

.atoi3:
	mov rcx, 10 ; mul by 10 for place
	mul rcx
	movzx rbx, byte[r11]
	inc r11
	mov rcx, 0
	cmp rbx, rcx
	je .next1
	mov rcx, 0x30
	sub rbx, rcx
	add rax, rbx
	jmp .atoi3

.next1:
	mov rcx, 10	; extra 0 needs to be dropped
	div rcx
	mov r13, rax
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; do the adding
.adding:
	; r12 contains value one/sum
	; r13 contains value two
	; r14 contains carry value
	mov rax, 0
	mov r14, 0
	mov r14, r12
	; AND op1(dest), op2
	and r14, r13  ; carry bits = val1 AND val2
	xor r12, r13  ; val1 = val1 XOR val2
	shl r14, 1    ; shift r14 left 1 bit
	mov r13, r14  ; place into val2
	mov rax, 0
	cmp r13, rax  ; check if val2 is equal to 0
	jne .adding

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; printing
.onedigit:
	mov rax, 0
	mov rax, 9
	cmp r12, rax
	jg .twodigits
	
	mov rax, 0
	mov rdx, 0
	mov rax, r12
	add rax, 0x30
	mov [one+0], rax
	mov rax, 0
	mov rax, 0xA
	mov [one+1], rax

	mov rax, 1
	mov rdi, 2
	mov rsi, one
	mov rdx, 2
	syscall
	jmp .exit

.twodigits:
	mov rax, 0
	mov rax, 99
	cmp r12, rax
	jg .threedigits
	
	mov rax, 0
	mov rdx, 0
	mov rax, r12
	mov r10, 10
	div r10
	mov r9, 0
	mov r10, 0
	mov r9, rax
	mov r10, rdx
	add r9, 0x30
	add r10, 0x30
	mov r11, 0
	mov r11, 0xA
	mov [two+0], r9
	mov [two+1], r10
	mov [two+2], r11

	mov rax, 0
	mov rax, 1
	mov rdi, 2
	mov rsi, two
	mov rdx, 0
	mov rdx, 3
	syscall
	jmp .exit

.threedigits:
	mov rax, 0
	mov rdx, 0
	mov rax, r12
	mov r10, 100
	div r10
	mov r9, rax
	add r9, 0x30
	mov [three+0], r9
	mov rax, 0
	mov rax, 9
	cmp rax, rdx
	jg .three0x

	mov rax, 0
	mov rax, rdx
	mov rdx, 0
	mov r10, 10
	div r10
	mov r9, rax
	mov r10, rdx
	add r9, 0x30
	add r10, 0x30
	mov [three+1], r9
	mov [three+2], r10
	mov r11, 0xA
	mov [three+3], r11
	jmp .threeprint

.three0x:
	mov r9, 0x30
	mov r10, rdx
	add r10, 0x30
	mov [three+1], r9
	mov [three+2], r10
	mov r11, 0xA
	mov [three+3], r11

.threeprint:
	mov rax, 0
	mov rax, 1
	mov rdi, 2
	mov rsi, three
	mov rdx, 0
	mov rdx, 4
	syscall

.exit:
	mov rax, 60
	mov rdi, 0
	syscall



