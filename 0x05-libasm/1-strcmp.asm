BITS 64

global asm_strcmp

asm_strcmp:
	push rbp
	mov rbp, rsp
	mov QWORD [rbp - 8], rdi
	mov QWORD [rbp -16], rsi
	jmp walk_str
step_str:
	add QWORD [rbp - 8], 1
	add QWORD [rbp - 16], 1
walk_str:
	mov rax, QWORD [rbp -8]
	movzx eax, BYTE [rax]
	test al, al
	je test_s1_s2_may
	mov rax, QWORD [rbp - 16]
	movzx eax, BYTE [rax]
	test al, al
	je test_s1_s2_may
	mov rax, QWORD [rbp - 8]
	movzx edx, BYTE [rax]
	mov rax, QWORD [rbp -16]
	movzx eax, BYTE [rax]
	cmp dl, al
	je step_str
test_s1_s2_may:
	mov rax, QWORD [rbp -8]
	movzx edx, BYTE [rax]
	mov rax, QWORD [rbp - 16]
	movzx eax, BYTE [rax]
	cmp dl, al
	jle test_s1_s2_min
	mov eax, 1
	jmp return
test_s1_s2_min:
	mov rax, QWORD [rbp - 8]
	movzx edx, BYTE [rax]
	mov rax, QWORD [rbp - 16]
	movzx eax, BYTE [rax]
	cmp dl, al
	jge return_0
	mov eax, -1
	jmp return
return_0:
	mov eax, 0
return:
	pop rbp
	ret