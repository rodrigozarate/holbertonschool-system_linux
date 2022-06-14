BITS 64

global asm_putc

asm_putc:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov DWORD [rbp - 4], edi
	lea rax, [rbp - 4]
	mov edx, 1
	mov rsi, rax
	mov edi, 1
	mov eax, 1
	syscall
	leave
	ret
