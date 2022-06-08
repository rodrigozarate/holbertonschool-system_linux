BITS 64

global asm_strlen
asm_strlen:
	push	rbp
	mov		rbp, rsp
	mov		QWORD [rbp - 24], rdi
	mov 	QWORD [rbp - 8], 0
	jmp		.tests_null
.str_len_plus:
	add		QWORD [rbp - 8], 1
	add		QWORD [rbp - 24], 1
.tests_null:
	mov		rax, QWORD [rbp - 24]
	movzx	eax, BYTE [rax]
	test	al, al
	jne		.str_len_plus
	mov		rax, QWORD [rbp - 8]
	pop		rbp
	ret
