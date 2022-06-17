BITS 64

extern asm_strlen
extern asm_putc
global asm_puti_base

asm_puti_base:
	push rbp
	mov rbp, rsp
	sub rsp, 48
	mov DWORD [rbp - 36], edi
	mov DWORD [rbp - 48], rsi
	mov DWORD [rbp - 4], 1
	mov QWORD [rbp - 16], 0
	mov QWORD [rbp - 24], 1
	mov rax, QWORD [rbp - 48]
	mov rdi, rax
	call asm_strlen
	mov DWORD [rbp - 28], eax
	cmp DWORD [rbp - 28], 1
	ja neg_v
	mov eax, 0
	jmp return
neg_v:
	cmp DWORD [rbp - 36], 0
	jns ch_p
	mov edi, 45
	call asm_putc
	add QWORD [rbp - 16], 1
	add QWORD [rbp - 24], 1
	mov eax, DWORD [rbp - 36]
	neg eax
	mov DWORD [rbp - 8], eax
	jmp mulxbs_test
ch_p:
	mov eax, DWORD [rbp - 36]
	mov DWORD [rbp - 8], eax
	jmp mulxbs_test
mulxbs:
	mov eax, DWORD [rbp - 4]
	imul eax, DWORD [rbp - 28]
	mov DWORD [rbp - 4], eax
	add QWORD [rbp - 24], 1
mulxbs_test:
	mov eax, DWORD [rbp - 8]
	mov edx, 0
	div DWORD [rbp - 28]
	cmp eax, DWORD [rbp - 4]
	jnb mulxbs
	jmp prnt_test
prnt:
	mov eax, DWORD [rbp - 8]
	mov edx, 0
	div DWORD [rbp - 4]
	mov edx, eax
	mov rax, QWORD [rbp - 48]
	add rax, rdx
	movzx eax, BYTE [rax]
	movsx eax, al
	mov edi, eax
	call asm_putc
	mov eax, DWORD [rbp - 8]
	mov edx, 0
	div DWORD [rbp - 4]
	mov DWORD [rbp - 8], edx
	mov eax, DWORD [rbp - 4]
	mov edx, 0
	div DWORD [rbp - 28]
	mov DWORD [rbp - 4], eax
	add QWORD [rbp - 16], 1
prnt_test:
	mov rax, QWORD [rbp - 16]
	cmp rax, QWORD [rbp - 24]
	jb prnt	
	mov rax, QWORD [rbp - 24]
return:
	leave
	ret