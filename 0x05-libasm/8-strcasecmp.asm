BITS 64

global asm_strcasecmp

asm_strcasecmp:
	push rbp
	mov rbp, rsp
	mov QWORD [rbp - 24], rdi
	mov QWORD [rbp - 32], rsi
	mov DWORD [rbp - 4], 0
	jmp dif_s1_s2
t_1:
	mov rax, QWORD [rbp - 24]
	movzx eax, BYTE [rax]
	cmp al, 64
	jle false_t_1
	mov rax, QWORD [rbp - 24]
	movzx eax, BYTE [rax]
	cmp al, 90
	jg false_t_1
	mov rax, QWORD [rbp - 24]
	movzx eax, BYTE [rax]
	add eax, 32
	jmp true_t_1
false_t_1:
	mov rax, QWORD [rbp - 24]
	movzx eax, BYTE [rax]
true_t_1:
	mov BYTE [rbp - 5], al
	mov rax, QWORD [rbp - 32]
	movzx eax, BYTE [rax]
	cmp al, 64
	jle false_t_2
	mov rax, QWORD [rbp - 32]
	movzx eax, BYTE [rax]
	cmp al, 90
	jg false_t_2
	mov rax, QWORD [rbp - 32]
	movzx eax, BYTE [rax]
	add eax, 32	
	jmp dif_search
false_t_2:
	mov rax, QWORD [rbp - 32]
	movzx eax, BYTE [rax]
dif_search:
	mov BYTE [rbp - 6], al
	movsx edx, BYTE [rbp - 5]
	movsx eax, BYTE [rbp - 6]
	sub edx, eax
	mov eax, edx
	mov DWORD [rbp - 4], eax
	add QWORD [rbp - 24], 1
	add QWORD [rbp - 32], 1
dif_s1_s2:
	mov rax, QWORD [rbp - 24]
	movzx eax, BYTE [rax]
	test al, al
	jne dif_test
	mov rax, QWORD [rbp - 32]
	movzx eax, BYTE [rax]
	test al, al
	je dif_ret
dif_test:
	cmp DWORD [rbp - 4], 0
	je t_1
dif_ret:
	mov eax, DWORD [rbp - 4]
	pop rbp
	ret
