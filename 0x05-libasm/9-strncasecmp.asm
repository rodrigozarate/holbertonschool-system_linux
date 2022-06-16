BITS 64

global asm_strncasecmp

asm_strncasecmp:
	push rbp
	mov rbp, rsp
	mov QWORD [rbp - 24], rdi
	mov QWORD [rbp - 32], rsi
	mov QWORD [rbp - 40], rdx
	mov QWORD [rbp - 8], 0
	mov DWORD [rbp - 12], 0
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
	mov BYTE [rbp - 13], al
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
	mov BYTE [rbp - 14], al
	movsx edx, BYTE [rbp - 13]
	movsx eax, BYTE [rbp - 14]
	sub edx, eax
	mov eax, edx
	mov DWORD [rbp - 12], eax
	add QWORD [rbp - 24], 1
	add QWORD [rbp - 32], 1
	add QWORD [rbp - 8], 1
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
	cmp DWORD [rbp - 12], 0
	jne dif_ret
	mov rax, QWORD [rbp - 8]
	cmp rax, QWORD [rbp - 40]
	jb t_1
dif_ret:
	mov eax, DWORD [rbp - 12]
	pop rbp
	ret
