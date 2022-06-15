BITS 64

extern asm_strlen
global asm_puts

asm_puts:
	push    rbp
	mov rbp, rsp
	sub rsp, 32
	mov QWORD [rbp - 24], rdi
	mov rax, QWORD [rbp - 24]
	mov rdi, rax
	mov eax, 0
	call asm_strlen
	mov DWORD [rbp - 4], eax
	mov edx, DWORD [rbp - 4]
	mov rax, QWORD [rbp - 24]
	mov rsi, rax
	mov edi, 1
	mov eax, 1
	syscall
	cdqe
	leave
	ret