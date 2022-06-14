BITS 64

global asm_strstr
asm_strstr:
	push rbp
	mov rpb, rsp
	mov QWORD [rbp - 40], rdi
	mov QWORD [rbp - 48], rsi
	mov rax, QWORD [rbp - 40]
	mov QWORD [rbp - 8], rax
	mov rax, QWORD [rbp - 48]
	mov QWORD [rbp - 24], rax
	mov QWORD [rbp - 16], 0
	mov rax, QWORD [rbp - 24]
	movzx eax, BYTE [rax]
	test al, al
	jne loop_1
	jmp ret_hstk
loop_ini:
	mov rax, QWORD [rbp - 24]
	mov QWORD [rbp - 16], rax
	jmp loop_2
base_loop:
	mov rax, QWORD [rbp - 16]
	movzx edx, BYTE [rax]
	mov rcx, QWORD [rbp - 16]
	mov rax, QWORD [rbp - 24]
	sub rcx, rax
	mov rax, rcx
	mov rcx, rax
	mov rax, QWORD [rbp - 8]
	add rax, rcx
	movzx eax, BYTE [rax]
	cmp dl, al
	je walk
walk:
	add QWORD [rbp - 16], 1
loop_2:
	mov rax, QWORD [rbp - 16]
	movzx eax, BYTE [rax]
	test al, al
	jne base_loop
test_al:
	mov rax, QWORD[rbp - 16]
	movzx eax, BYTE [rax]
	test al, al
	jne walk_hstk
ret_hstk:
	mov rax, QWORD [rbp - 8]
	jmp return
walk_hstk:
	add QWORD [rbp - 8], 1
loop_1:
	mov rax, QWORD [rbp - 8]
	movzx eax, BYTE [rax]
	test al, al
	jne loop_ini
ret_null:
	mov eax, 0
return:
	pop rbp
	ret
