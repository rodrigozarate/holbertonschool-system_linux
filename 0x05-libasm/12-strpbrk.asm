BITS 64

global asm_strpbrk

asm_strpbrk:
	push rbp
	mov rbp, rsp
	mov QWORD [rbp - 24], rdi
	mov QWORD [rbp - 32], rsi
	mov QWORD [rbp - 8], 0
	jmp base_loop
cmp_loop:
	mov rax, QWORD [rbp - 32]
	mov QWORD [rbp - 8], rax
	jmp tmp_loop
ini_t:
	add QWORD [rbp - 8], 1
tmp_loop:
	mov rax, QWORD [rbp - 8]
	movzx eax, BYTE [rax]
	test al, al
	je  cmp_tmp
	mov rax, QWORD [rbp - 8]
	movzx edx, BYTE [rax]
	mov rax, QWORD [rbp - 24]
	movzx eax, BYTE [rax]
	cmp dl, al
	jne ini_t
cmp_tmp:
	mov rax, QWORD [rbp - 8]
	movzx eax, BYTE [rax]
	test al, al
	jne plus_var
	jmp cmp_loop_aftr
plus_var:
	add QWORD [rbp - 24], 1
base_loop:
	mov rax, QWORD [rbp - 24]
	movzx eax, BYTE [rax]
	test al, al
	jne cmp_loop
cmp_loop_aftr:
	cmp QWORD [rbp - 8], 0
	je return_null
	mov rax, QWORD [rbp - 8]
	movzx eax, BYTE [rax]
	test al, al
	je return_null
	mov rax, QWORD [rbp - 24]
	jmp return
return_null:
	mov eax, 0
return:
	pop rbp
	ret

