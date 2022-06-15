BITS 64

global asm_memcpy

asm_memcpy:
	push rbp
	mov rbp, rsp
	mov QWORD [rbp - 40], rdi
	mov QWORD [rbp - 48], rsi
	mov QWORD [rbp - 56], rdx
	mov rax, QWORD [rbp - 40]
	mov QWORD [rbp - 16], rax
	mov rax, QWORD [rbp - 48]
	mov QWORD [rbp - 24], rax
	cmp QWORD [rbp - 16], 0
	je  mem_loc
	cmp QWORD [rbp - 24], 0
	jne  loop_ini
mem_loc:
	mov rax, QWORD [rbp - 40]
	jmp return
loop_ini:
	mov QWORD [rbp - 8], 0
	jmp count_loop_test
count_loop:
	mov rax, QWORD [rbp - 8]
	mov rdx, QWORD [rbp - 16]
	add rdx, rax
	mov rax, QWORD [rbp - 8]
	mov rcx, QWORD [rbp - 24]
	add rax, rcx
	movzx   eax, BYTE [rax]
	mov BYTE [rdx], al
	add QWORD [rbp - 8], 1
count_loop_test:
	mov rax, QWORD [rbp - 8]
	cmp rax, QWORD [rbp - 56]
	jb  count_loop
	mov rax, QWORD [rbp - 40]
return:
	pop rbp
	ret
