section .data
	newline db " "
	oneD    db "  "
	twoD    db "   "
	threeD  db "2 3 "
	fourD	db "     "
	fiveD	db "      "
	primeCount db "      "


section .text
global _start

_start:
					 ; Preserves: rsp rbp rbx r12 r13 r14 r15

.atoi:

    pop r11          ; Argc
    pop r11          ; Argv[0] - program name
    pop r11          ; Argv[1] - number of primes
    mov rcx, 0
    cmp rcx, r11
;   je .error
    mov r12, 0       ; Set up for atoi
    mov rax, 0

.atoi2:
    mov rcx, 10      ; Mul by 10 for place
    mul rcx          ;
    movzx rbx, byte[r11]
    inc r11
    mov rcx, 0
    cmp rbx, rcx     ; This took me way too long to figure out
    je .initialvalues
    mov rcx, 0x30
    sub rbx, rcx
    add rax, rbx
    jmp .atoi2

.initialvalues:
    mov rcx, 10      ; Extra 0 needs to be dropped
    div rcx
    mov r12, rax
    mov rbx, 3       ; Approx. sqrt
;   mov r12          ; Max number of primes is r1224	 ; Max number of primes
	mov r13, 4		 ; r13 HOLDS THE TEST NUMBER 
	mov r14, 2		 ; r14 HOLDS THE DIVISOR
	mov r15, 2		 ; Prime count here
	
	mov rax, 0
	mov rax, 1		 ; Print the contents of one
	mov rdi, 1
	mov rsi, threeD  
	mov rdx, 4 
	syscall


.primecheck:	
	mov rax, 0		 ; 0 things out
	mov rdx, 0

	mov rax, r13	 ; Move the test number to rax to be divided
	div r14			 ; Divide rax by r14, quo goes to rax, remainder to rdx

	mov r8, 0	     ; Temp value used for comparing stuff, volatile
	mov r9, rdx
	cmp r9, r8      ; Is the remainder greater than 0?
	je .notprime	 ; When the remainder is 0, do this jump
	
	inc r14			 ; Not yet composite, up the divisor
	cmp r13, r14	 ; See if the divisor is the same as the test num
	je .print		 ; If it is, then the number is prime

	jmp .primecheck  ; Go back through the process loop

.notprime:
	mov rax, 0
	mov rdx, 0
	inc r13			 ; New number, old one was not prime
	mov r14, 2	     ; Reset the divisor
	jmp .primecheck  ; Back to the start

.print:				 ; Print things here
	mov r8, 0
	mov r8, 10		 ; Test to see how many digits we have
	cmp r13, r8
	jl .one
	mov r8, 0
	mov r8, 100
	cmp r13, r8
	jl .two
	mov r8, 0
	mov r8, 1000
	cmp r13, r8
	jl .three
	mov r8, 0
	mov r8, 10000
	cmp r13, r8
	jl .four
	
	jmp .five

.one:
	mov rax, 0		 ; Empty rax
	mov rdx, 0
	mov rax, r13	 ; Put test number in rax
	add rax, 0x30 	 ; Make it an ascii number
	mov [oneD+0], rax
	mov rax, 0 			
	mov rax, 0x20	 ; Put a space into the array
	mov [oneD+1], rax 

	mov rax, 1		 ; Print the contents of one
	mov rdi, 2
	mov rsi, oneD
	mov rdx, 2 
	syscall

	mov rsi, 0
	jmp .check	     ; See if we are done

.two:
	mov rax, 0		 ; 0 things out
	mov rdx, 0
	mov rax, r13		 ; Put test number into rax
	mov r10, 10		 ; Put a 10 into r10
	div r10
	mov r9, 0
	mov r10, 0
	mov r9, rax
	mov r10, rdx
	add r9, 0x30
	add r10, 0x30
	mov r11, 0x20
	mov [twoD+0], r9
	mov [twoD+1], r10 
	mov [twoD+2], r11 
	
	mov rax, 0	     ; Print things
	mov rax, 1
	mov rsi, 2
	mov rsi, twoD
	mov rdx, 0
	mov rdx, 3
	syscall

	jmp .check

.three:
	mov rax, 0       ; Just clearing stuff because stuff keeps breaking if i dont
	mov rdx, 0 
	mov rax, r13
	mov r10, 100
	div r10
	mov r9,  rax
	add r9, 0x30    ; Turn the first value into an ascii char
	mov [threeD+0], r9
	mov rax, 0
	mov rax, 9
	cmp  rax, rdx
	jg .three_zero_x ; Logic starts getting weird here
					  ; but this goes the division error
	mov rax, 0
	mov rax, rdx
	mov rdx, 0
	mov r10, 10
	div r10
	mov r9, rax
	mov r10, rdx	 ; Lack of comments as the process is just kind of repeating
	add r9, 0x30
	add r10, 0x30
	mov [threeD+1], r9
	mov [threeD+2], r10
	mov r11, 0x20
	mov [threeD+3], r11
	jmp .three_print
	
.three_zero_x:
	mov r9, 0x30
	mov r10, rdx
	add r10, 0x30
	mov [threeD+1], r9
	mov [threeD+2], r10
	mov r11, 0x20
	mov [threeD+3], r11

.three_print:	
	mov rax, 0
	mov rax, 1
	mov rsi, 2
	mov rsi, threeD
	mov rdx, 0
	mov rdx, 4
	syscall	
	jmp  .check

.four:
	mov rax, 0       ; Clear everything out to be safe
	mov rdx, 0 
	mov r8, 0
	mov r9, 0
	mov r10, 0
	mov r11, 0

	mov rax, r13	 ; Test number to rax
	mov r8, 1000     ; Use this to isolate thousands place
	div r8		     ; Divide rax by r8(1000)
	mov r9, rax      ; Quotient to r9
	mov r10, rdx	 ; Remainder to r10
	
	mov rax, 0	 	 ; Clean up
	mov rdx, 0

	add r9, 0x30	 ; Ascii-ify thousands
	mov [fourD+0], r9
	
	mov r9, 0		 ; Clean
	mov r8, 0		 ; Now the last three digits sit in r10

	mov rax, r10
	mov r8, 100
	cmp rax, r8		 ; Check for a zero in the hundreds place
	jg .four_jump_01
	mov r8, 0
	add r8, 0x30
	mov [fourD+1], r8
	mov r8, 0		 ; Set the 0 and then clean
	jmp .four_jump_02

.four_jump_01:
	div r8
	mov r9, rax
	mov r10, rdx
	mov rax, 0
	mov rdx, 0
	add r9, 0x30     ; Ascii-ify hundreds place here 
	mov [fourD+1], r9
	
.four_jump_02:
	mov rax, 0
	mov rdx, 0
	mov r8, 0
	mov r9, 0
	
	mov rax, r10     ; Check for zero in tens place
	mov r8, 10
	cmp  rax, r8
	jg .four_jump_03
	mov r8, 0
	add r8, 0x30
	mov [fourD+2], r8
	mov r8, 0
	jmp .four_jump_final

.four_jump_03:
	div r8			 ; Divide the remaining number by 10
	mov r9, 0
	mov r9, 0
	mov r9, rax
	add r9, 0x30
	mov r10, rdx     ; Same as above mostly 
	
	mov [fourD+2], r9

.four_jump_final:
	add r10, 0x30
	mov [fourD+3], r10
	mov r8, 0
	mov r8, 0x20
	mov [fourD+4], r8

.four_print:
	mov rax, 0
	mov rax, 1
	mov rsi, 2
	mov rsi, fourD
	mov rdx, 0
	mov rdx, 5
	syscall	
	jmp  .check



.five:
	mov rax, 0       ; Clear everything out to be safe
	mov rdx, 0 
	mov r8, 0
	mov r9, 0
	mov r10, 0
	mov r11, 0

	mov rax, r13	 ; Test number to rax
	mov r8, 10000     ; Use this to isolate thousands place
	div r8		     ; Divide rax by r8(1000)
	mov r9, rax      ; Quotient to r9
	mov r10, rdx	 ; Remainder to r10
	
	mov rax, 0	 	 ; Clean up
	mov rdx, 0

	add r9, 0x30	 ; Ascii-ify thousands
	mov [fiveD+0], r9
	
	mov r9, 0		 ; Clean
	mov r8, 0		 ; Now the last four digits sit in r10

	mov rax, r10
	mov r8, 1000
	cmp rax, r8		 ; Check for a zero in the thousands place
	jg .five_jump_01
	mov r8, 0
	add r8, 0x30
	mov [fiveD+1], r8
	mov r8, 0		 ; Set the 0 and then clean
	jmp .five_jump_02

.five_jump_01:
	div r8
	mov r9, rax
	mov r10, rdx
	mov rax, 0
	mov rdx, 0
	add r9, 0x30     ; Ascii-ify thousands place here 
	mov [fiveD+1], r9
	
.five_jump_02:
	mov rax, 0
	mov rdx, 0
	mov r8, 0
	mov r9, 0
	
	mov rax, r10     ; Check for zero in tens place
	mov r8, 100
	cmp  rax, r8
	jg .five_jump_03
	mov r8, 0
	add r8, 0x30
	mov [fiveD+2], r8
	mov r8, 0
	jmp .five_jump_04

.five_jump_03:
	mov rdx, 0
	mov r9, 0
	div r8			 ; Divide the remaining number by 100
	mov r9, rax
	add r9, 0x30
	mov r10, rdx     ; Same as above mostly 
	
	mov [fiveD+2], r9
	jmp .five_jump_05

.five_jump_04:
	mov rax, 0
	mov rdx, 0
	mov r8, 0
	mov r9, 0
	
	mov rax, r10     ; Check for zero in tens place
	mov r8, 10
	cmp  rax, r8
	jg .five_jump_05
	mov r8, 0
	add r8, 0x30
	mov [fiveD+3], r8
	mov r8, 0
	jmp .five_jump_final

.five_jump_05:
	mov rdx, 0 ;---------------------my code explodes without this 
	div r8			 ; Divide the remaining number by 10
	mov r9, 0
	mov r9, rax
	add r9, 0x30
	mov r10, rdx     ; Same as above mostly 
	
	mov [fiveD+3], r9


.five_jump_final:
	add r10, 0x30
	mov [fiveD+4], r10
	mov r8, 0
	mov r8, 0x20
	mov [fiveD+5], r8

.five_print:
	mov rax, 0
	mov rax, 1
	mov rsi, 2
	mov rsi, fiveD
	mov rdx, 0
	mov rdx, 6
	syscall	
	jmp  .check


.check:
	inc r13			 ; Test number upped
	mov r14, 2		 ; Reset the divsior
	inc r15			 ; Up the prime count
	cmp r12, r15
	jle .exit

	jmp .primecheck  ; Back to the start

.exit:
	mov rax, 0
	mov rax, 1
	mov rsi, 0
	mov r8, 0 
	add r8, 0xa
	mov [newline+0], r8
	mov rsi, newline
	mov rdx, 0
	mov rdx, 6
	syscall

	mov rax, 60 	 ; 60 - syscall exit
	mov rdi, 0
	syscall
