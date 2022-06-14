BITS 64

global asm_strncmp

asm_strncmp:
	push rbp
	mov rbp, rsp
	mov QWORD [rbp - 40], rdi
	mov QWORD [rbp - 32], rsi
	mov QWORD [rbp - 24], rdx
	mov QWORD [rbp - 16], 0
	mov QWORD [rbp - 8], 0
	jmp s1_s2_n_null
walk_str:
	mov rax, QWORD [rbp - 24]
	movzx rax, BYTE [rax]
	movsx rdx, al
	mov rax, QWORD [rbp - 32]
	movzx rax, BYTE [rax]
	movsx rax, al
	sub rdx, rax
	mov rax, rdx
	mov QWORD [rbp - 16], rax
	add QWORD [rbp - 24], 1
	add QWORD [rbp - 32], 1
	add QWORD [rbp - 8], 1
s1_s2_n_null:
	mov rax, QWORD [rbp - 24]
	movzx rax, BYTE [rax]
	test al, al
	jne n_eq_test
	mov rax, QWORD [rbp - 32]
	movzx rax, BYTE [rax]
	test al, al
	je eq_test_may
n_eq_test:
	cmp QWORD [rbp - 16], 0
	jne eq_test_may
	mov rax, QWORD [rbp - 8]
	cmp rax, QWORD [rbp - 40]
	jb walk_str
eq_test_may:
	cmp QWORD [rbp - 16], 0
	jle eq_test_min
	mov rax, 1
	jmp end_1
eq_test_min:
	cmp QWORD [rbp - 16], 0
	jns end_0
	mov rax, -1
	jmp end_1
end_0:
	mov rax, 0
end_1:
	pop rbp
	ret
