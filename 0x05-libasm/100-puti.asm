BITS 64

extern asm_strlen
extern asm_putc
global asm_puti

asm_puti:
	push rbp
	mov rbp, rsp
	sub     rsp, 48
	mov     DWORD [rbp - 36], edi
	mov     DWORD [rbp - 4], 1
	mov     QWORD [rbp - 16], 0
	mov     QWORD [rbp - 24], 1
	cmp     DWORD [rbp - 36], 0
	jns     ntt_c
	mov     edi, 45
	call    asm_putc
	add     QWORD [rbp - 16], 1
	add     QWORD [rbp - 24], 1
	mov     eax, DWORD [rbp - 36]
	neg     eax
	mov     DWORD [rbp - 8], eax
	jmp     mulx10_test
ntt_c:
	mov     eax, DWORD [rbp - 36]
	mov     DWORD [rbp - 8], eax
	jmp     mulx10_test
mulx10:
	mov     eax, DWORD [rbp - 4]
	imul    eax, 10
	mov     DWORD [rbp - 4], eax
	add     QWORD [rbp - 24], 1
mulx10_test:
	mov     eax, DWORD [rbp - 8]
	mov     edx, 0
	mov	rcx, 10
	div     rcx
	cmp     eax, DWORD [rbp - 4]
	jnb     mulx10
	jmp     prnt_test
prnt:
	mov     eax, DWORD [rbp - 8]
	mov     edx, 0
	div     DWORD [rbp - 4]
	add     eax, 48
	mov     edi, eax
	call    asm_putc
	mov     eax, DWORD [rbp - 8]
	mov     edx, 0
	div     DWORD [rbp - 4]
	mov     DWORD [rbp - 8], edx
	mov     eax, DWORD [rbp - 4]
	mov     edx, 0
	mov	rcx, 10
	div 	rcx
	mov     DWORD [rbp - 4], eax
	add     QWORD [rbp - 16], 1
prnt_test:
	mov     rax, QWORD [rbp - 16]
	cmp     rax, QWORD [rbp - 24]
	jb      prnt
	mov     rax, QWORD [rbp - 24]
	leave
	ret
