BITS 64

global

asm_strspn:
	push rbp
	mov rbp, rsp
	mov QWORD [rbp - 24], rdi
	mov QWORD [rbp - 32], rsi
	mov QWORD [rbp - 8], 0
	mov QWORD [rbp - 16], 0
	jmp base_loop
cmp_loop:
	mov rax, QWORD [rbp - 32]
	mov QWORD [rbp - 16], rax
	jmp tmp_loop
ini_t:
	add QWORD [rbp - 16], 1
tmp_loop:
	mov rax, QWORD [rbp - 16]
	movzx eax, BYTE [rax]
	test al, al
	je  cmp_tmp
	mov rax, QWORD [rbp - 16]
	movzx edx, BYTE [rax]
	mov rax, QWORD [rbp - 24]
	movzx eax, BYTE [rax]
	cmp dl, al
	jne ini_t
cmp_tmp:
	mov rax, QWORD [rbp - 16]
	movzx eax, BYTE [rax]
	test al, al
	jne plus_var
	jmp return
plus_var:
	add QWORD [rbp - 8], 1
	add QWORD [rbp - 24], 1
base_loop:
	mov rax, QWORD [rbp - 24]
	movzx eax, BYTE [rax]
	test al, al
	jne cmp_loop
return:
	mov rax, QWORD [rbp - 8]
	pop rbp
	ret
