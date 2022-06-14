BITS 64

global asm_strchr

asm_strchr:
	push rbp
	mov rbp, rsp
	mov QWORD [rbp - 24], rdi
	mov DWORD [rbp - 16], esi
	mov rax, QWORD [rbp - 24]
	mov QWORD [rbp - 8], rax
	jmp null_test
walk_str:
	mov rax, QWORD [rbp - 8]
	movzx eax, BYTE [rax]
	movsx eax, al
	cmp eax, DWORD [rbp - 16]
	jne cont
	mov rax, QWORD [rbp - 8]
	jmp end_n
cont:
	add QWORD [rbp - 8], 1
null_test:
	mov rax, QWORD [rbp - 8]
	movzx eax, BYTE [rax]
	test al, al
	jne walk_str
	cmp DWORD [rbp - 16], 0
	jne end_x
	mov rax, QWORD [rbp - 8]
	jmp end_n
end_x:
	mov eax, 0
end_n:
	pop rbp
	ret
