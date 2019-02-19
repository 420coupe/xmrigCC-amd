PUBLIC CryptonightR_template_part1
PUBLIC CryptonightR_template_mainloop
PUBLIC CryptonightR_template_part2
PUBLIC CryptonightR_template_part3
PUBLIC CryptonightR_template_end
PUBLIC CryptonightR_template_double_part1
PUBLIC CryptonightR_template_double_mainloop
PUBLIC CryptonightR_template_double_part2
PUBLIC CryptonightR_template_double_part3
PUBLIC CryptonightR_template_double_part4
PUBLIC CryptonightR_template_double_end

 CryptonightR_template_part1:
	mov	QWORD PTR [rsp+16], rbx
	mov	QWORD PTR [rsp+24], rbp
	mov	QWORD PTR [rsp+32], rsi
	push	r10
	push	r11
	push	r12
	push	r13
	push	r14
	push	r15
	push	rdi
	sub	rsp, 64
	mov	r12, rcx
	mov	r8, QWORD PTR [r12+32]
	mov	rdx, r12
	xor	r8, QWORD PTR [r12]
	mov	r15, QWORD PTR [r12+40]
	mov	r9, r8
	xor	r15, QWORD PTR [r12+8]
	mov	r11, QWORD PTR [r12+224]
	mov	r12, QWORD PTR [r12+56]
	xor	r12, QWORD PTR [rdx+24]
	mov	rax, QWORD PTR [rdx+48]
	xor	rax, QWORD PTR [rdx+16]
	movaps	XMMWORD PTR [rsp+48], xmm6
	movd	xmm0, r12
	movaps	XMMWORD PTR [rsp+32], xmm7
	movaps	XMMWORD PTR [rsp+16], xmm8
	movaps	XMMWORD PTR [rsp], xmm9
	mov	r12, QWORD PTR [rdx+88]
	xor	r12, QWORD PTR [rdx+72]
	movd	xmm6, rax
	mov	rax, QWORD PTR [rdx+80]
	xor	rax, QWORD PTR [rdx+64]
	punpcklqdq xmm6, xmm0
	and	r9d, 2097136
	movd	xmm0, r12
	movd	xmm7, rax
	punpcklqdq xmm7, xmm0
	mov r10d, r9d
	movd	xmm9, rsp
	mov rsp, r8
	mov	r8d, 524288

 	mov	ebx, [rdx+96]
	mov	esi, [rdx+100]
	mov	edi, [rdx+104]
	mov	ebp, [rdx+108]

 	ALIGN(64)
CryptonightR_template_mainloop:
	movdqa	xmm5, XMMWORD PTR [r9+r11]
	movd	xmm0, r15
	movd	xmm4, rsp
	punpcklqdq xmm4, xmm0
	lea	rdx, QWORD PTR [r9+r11]

 	aesenc	xmm5, xmm4
	movd	r10d, xmm5
	and	r10d, 2097136

 	mov	r12d, r9d
	mov	eax, r9d
	xor	r9d, 48
	xor	r12d, 16
	xor	eax, 32
	movdqu	xmm0, XMMWORD PTR [r9+r11]
	movdqu	xmm2, XMMWORD PTR [r12+r11]
	movdqu	xmm1, XMMWORD PTR [rax+r11]
	paddq	xmm0, xmm7
	paddq	xmm2, xmm6
	paddq	xmm1, xmm4
	movdqu	XMMWORD PTR [r12+r11], xmm0
	movd	r12, xmm5
	movdqu	XMMWORD PTR [rax+r11], xmm2
	movdqu	XMMWORD PTR [r9+r11], xmm1

 	movdqa	xmm0, xmm5
	pxor	xmm0, xmm6
	movdqu	XMMWORD PTR [rdx], xmm0

 	lea	r13d, [ebx+esi]
	lea	edx, [edi+ebp]
	shl rdx, 32
	or	r13, rdx

 	xor	r13, QWORD PTR [r10+r11]
	mov	r14, QWORD PTR [r10+r11+8]

 	movd eax, xmm6
	movd edx, xmm7

 CryptonightR_template_part2:
	mov	rax, r13
	mul	r12
	movd	xmm0, rax
	movd	xmm3, rdx
	punpcklqdq xmm3, xmm0

 	mov	r9d, r10d
	mov	r12d, r10d
	xor	r9d, 16
	xor	r12d, 32
	xor	r10d, 48
	movdqa	xmm1, XMMWORD PTR [r12+r11]
	xor	rdx, QWORD PTR [r12+r11]
	xor	rax, QWORD PTR [r11+r12+8]
	movdqa	xmm2, XMMWORD PTR [r9+r11]
	pxor	xmm3, xmm2
	paddq	xmm7, XMMWORD PTR [r10+r11]
	paddq	xmm1, xmm4
	paddq	xmm3, xmm6
	movdqu	XMMWORD PTR [r9+r11], xmm7
	movdqu	XMMWORD PTR [r12+r11], xmm3
	movdqu	XMMWORD PTR [r10+r11], xmm1

 	movdqa	xmm7, xmm6
	add	r15, rax
	add	rsp, rdx
	xor	r10, 48
	mov	QWORD PTR [r10+r11], rsp
	xor	rsp, r13
	mov	r9d, esp
	mov	QWORD PTR [r10+r11+8], r15
	and	r9d, 2097136
	xor	r15, r14
	movdqa	xmm6, xmm5
	dec	r8d
	jnz	CryptonightR_template_mainloop

 CryptonightR_template_part3:
	movd	rsp, xmm9

 	mov	rbx, QWORD PTR [rsp+136]
	mov	rbp, QWORD PTR [rsp+144]
	mov	rsi, QWORD PTR [rsp+152]
	movaps	xmm6, XMMWORD PTR [rsp+48]
	movaps	xmm7, XMMWORD PTR [rsp+32]
	movaps	xmm8, XMMWORD PTR [rsp+16]
	movaps	xmm9, XMMWORD PTR [rsp]
	add	rsp, 64
	pop	rdi
	pop	r15
	pop	r14
	pop	r13
	pop	r12
	pop	r11
	pop	r10
	ret	0
CryptonightR_template_end:

 ALIGN(64)
CryptonightR_template_double_part1:
	mov	QWORD PTR [rsp+24], rbx
	push	rbp
	push	rsi
	push	rdi
	push	r12
	push	r13
	push	r14
	push	r15
	sub	rsp, 320
	mov	r14, QWORD PTR [rcx+32]
	mov	r8, rcx
	xor	r14, QWORD PTR [rcx]
	mov	r12, QWORD PTR [rcx+40]
	mov	ebx, r14d
	mov	rsi, QWORD PTR [rcx+224]
	and	ebx, 2097136
	xor	r12, QWORD PTR [rcx+8]
	mov	rcx, QWORD PTR [rcx+56]
	xor	rcx, QWORD PTR [r8+24]
	mov	rax, QWORD PTR [r8+48]
	xor	rax, QWORD PTR [r8+16]
	mov	r15, QWORD PTR [rdx+32]
	xor	r15, QWORD PTR [rdx]
	movd	xmm0, rcx
	mov	rcx, QWORD PTR [r8+88]
	xor	rcx, QWORD PTR [r8+72]
	mov	r13, QWORD PTR [rdx+40]
	mov	rdi, QWORD PTR [rdx+224]
	xor	r13, QWORD PTR [rdx+8]
	movaps	XMMWORD PTR [rsp+160], xmm6
	movaps	XMMWORD PTR [rsp+176], xmm7
	movaps	XMMWORD PTR [rsp+192], xmm8
	movaps	XMMWORD PTR [rsp+208], xmm9
	movaps	XMMWORD PTR [rsp+224], xmm10
	movaps	XMMWORD PTR [rsp+240], xmm11
	movaps	XMMWORD PTR [rsp+256], xmm12
	movaps	XMMWORD PTR [rsp+272], xmm13
	movaps	XMMWORD PTR [rsp+288], xmm14
	movaps	XMMWORD PTR [rsp+304], xmm15
	movd	xmm7, rax
	mov	rax, QWORD PTR [r8+80]
	xor	rax, QWORD PTR [r8+64]

 	movaps xmm1, XMMWORD PTR [rdx+96]
	movaps xmm2, XMMWORD PTR [r8+96]
	movaps XMMWORD PTR [rsp], xmm1
	movaps XMMWORD PTR [rsp+16], xmm2

 	mov	r8d, r15d
	punpcklqdq xmm7, xmm0
	movd	xmm0, rcx
	mov	rcx, QWORD PTR [rdx+56]
	xor	rcx, QWORD PTR [rdx+24]
	movd	xmm9, rax
	mov	QWORD PTR [rsp+128], rsi
	mov	rax, QWORD PTR [rdx+48]
	xor	rax, QWORD PTR [rdx+16]
	punpcklqdq xmm9, xmm0
	movd	xmm0, rcx
	mov	rcx, QWORD PTR [rdx+88]
	xor	rcx, QWORD PTR [rdx+72]
	movd	xmm8, rax
	mov	QWORD PTR [rsp+136], rdi
	mov	rax, QWORD PTR [rdx+80]
	xor	rax, QWORD PTR [rdx+64]
	punpcklqdq xmm8, xmm0
	and	r8d, 2097136
	movd	xmm0, rcx
	mov	r11d, 524288
	movd	xmm10, rax
	punpcklqdq xmm10, xmm0
	
	movd xmm14, QWORD PTR [rsp+128]
	movd xmm15, QWORD PTR [rsp+136]

 	ALIGN(64)
CryptonightR_template_double_mainloop:
	movdqu	xmm6, XMMWORD PTR [rbx+rsi]
	movd	xmm0, r12
	mov	ecx, ebx
	movd	xmm3, r14
	punpcklqdq xmm3, xmm0
	xor	ebx, 16
	aesenc	xmm6, xmm3
	movd	rdx, xmm6
	movd	xmm4, r15
	movdqu	xmm0, XMMWORD PTR [rbx+rsi]
	xor	ebx, 48
	paddq	xmm0, xmm7
	movdqu	xmm1, XMMWORD PTR [rbx+rsi]
	movdqu	XMMWORD PTR [rbx+rsi], xmm0
	paddq	xmm1, xmm3
	xor	ebx, 16
	mov	eax, ebx
	xor	rax, 32
	movdqu	xmm0, XMMWORD PTR [rbx+rsi]
	movdqu	XMMWORD PTR [rbx+rsi], xmm1
	paddq	xmm0, xmm9
	movdqu	XMMWORD PTR [rax+rsi], xmm0
	movdqa	xmm0, xmm6
	pxor	xmm0, xmm7
	movdqu	XMMWORD PTR [rcx+rsi], xmm0
	mov	esi, edx
	movdqu	xmm5, XMMWORD PTR [r8+rdi]
	and	esi, 2097136
	mov	ecx, r8d
	movd	xmm0, r13
	punpcklqdq xmm4, xmm0
	xor	r8d, 16
	aesenc	xmm5, xmm4
	movdqu	xmm0, XMMWORD PTR [r8+rdi]
	xor	r8d, 48
	paddq	xmm0, xmm8
	movdqu	xmm1, XMMWORD PTR [r8+rdi]
	movdqu	XMMWORD PTR [r8+rdi], xmm0
	paddq	xmm1, xmm4
	xor	r8d, 16
	mov	eax, r8d
	xor	rax, 32
	movdqu	xmm0, XMMWORD PTR [r8+rdi]
	movdqu	XMMWORD PTR [r8+rdi], xmm1
	paddq	xmm0, xmm10
	movdqu	XMMWORD PTR [rax+rdi], xmm0
	movdqa	xmm0, xmm5
	pxor	xmm0, xmm8
	movdqu	XMMWORD PTR [rcx+rdi], xmm0
	movd	rdi, xmm5
	movd	rcx, xmm14
	mov	ebp, edi
	mov	r8, QWORD PTR [rcx+rsi]
	mov	r10, QWORD PTR [rcx+rsi+8]
	lea	r9, QWORD PTR [rcx+rsi]
	xor	esi, 16

 	movd xmm0, rsp
	movd xmm1, rsi
	movd xmm2, rdi
	movd xmm11, rbp
	movd xmm12, r15
	movd xmm13, rdx
	mov [rsp+112], rcx

 	mov ebx, DWORD PTR [rsp+16]
	mov esi, DWORD PTR [rsp+20]
	mov edi, DWORD PTR [rsp+24]
	mov ebp, DWORD PTR [rsp+28]

 	lea	eax, [ebx+esi]
	lea	edx, [edi+ebp]
	shl rdx, 32
	or	rax, rdx
	xor r8, rax

 	movd esp, xmm3
	pextrd r15d, xmm3, 2
	movd eax, xmm7
	movd edx, xmm9

 CryptonightR_template_double_part2:

 	movd rsp, xmm0
	mov DWORD PTR [rsp+16], ebx
	mov DWORD PTR [rsp+20], esi
	mov DWORD PTR [rsp+24], edi
	mov DWORD PTR [rsp+28], ebp

 	movd rsi, xmm1
	movd rdi, xmm2
	movd rbp, xmm11
	movd r15, xmm12
	movd rdx, xmm13
	mov rcx, [rsp+112]

 	mov rbx, r8
	mov	rax, r8
	mul	rdx
	and	ebp, 2097136
	mov	r8, rax
	movd	xmm1, rdx
	movd	xmm0, r8
	punpcklqdq xmm1, xmm0
	pxor	xmm1, XMMWORD PTR [rcx+rsi]
	xor	esi, 48
	paddq	xmm1, xmm7
	movdqu	xmm2, XMMWORD PTR [rsi+rcx]
	xor	rdx, QWORD PTR [rsi+rcx]
	paddq	xmm2, xmm3
	xor	r8, QWORD PTR [rsi+rcx+8]
	movdqu	XMMWORD PTR [rsi+rcx], xmm1
	xor	esi, 16
	mov	eax, esi
	mov	rsi, rcx
	movdqu	xmm0, XMMWORD PTR [rax+rcx]
	movdqu	XMMWORD PTR [rax+rcx], xmm2
	paddq	xmm0, xmm9
	add	r12, r8
	xor	rax, 32
	add	r14, rdx
	movdqa	xmm9, xmm7
	movdqa	xmm7, xmm6
	movdqu	XMMWORD PTR [rax+rcx], xmm0
	mov	QWORD PTR [r9+8], r12
	xor	r12, r10
	mov	QWORD PTR [r9], r14
	movd rcx, xmm15
	xor	r14, rbx
	mov	r10d, ebp
	mov	ebx, r14d
	xor	ebp, 16
	and	ebx, 2097136
	mov	r8, QWORD PTR [r10+rcx]
	mov	r9, QWORD PTR [r10+rcx+8]

 	movd xmm0, rsp
	movd xmm1, rbx
	movd xmm2, rsi
	movd xmm11, rdi
	movd xmm12, rbp
	movd xmm13, r15
	mov [rsp+104], rcx

 	mov ebx, DWORD PTR [rsp]
	mov esi, DWORD PTR [rsp+4]
	mov edi, DWORD PTR [rsp+8]
	mov ebp, DWORD PTR [rsp+12]

 	lea	eax, [ebx+esi]
	lea	edx, [edi+ebp]
	shl rdx, 32
	or	rax, rdx

 	xor r8, rax
	movd xmm3, r8

 	movd esp, xmm4
	pextrd r15d, xmm4, 2
	movd eax, xmm8
	movd edx, xmm10

 CryptonightR_template_double_part3:

 	movd rsp, xmm0
	mov DWORD PTR [rsp], ebx
	mov DWORD PTR [rsp+4], esi
	mov DWORD PTR [rsp+8], edi
	mov DWORD PTR [rsp+12], ebp

 	movd rbx, xmm1
	movd rsi, xmm2
	movd rdi, xmm11
	movd rbp, xmm12
	movd r15, xmm13
	mov rcx, [rsp+104]

 	mov rax, r8
	mul	rdi
	movd	xmm1, rdx
	movd	xmm0, rax
	punpcklqdq xmm1, xmm0
	mov	rdi, rcx
	mov	r8, rax
	pxor	xmm1, XMMWORD PTR [rbp+rcx]
	xor	ebp, 48
	paddq	xmm1, xmm8
	xor	r8, QWORD PTR [rbp+rcx+8]
	xor	rdx, QWORD PTR [rbp+rcx]
	add	r13, r8
	movdqu	xmm2, XMMWORD PTR [rbp+rcx]
	add	r15, rdx
	movdqu	XMMWORD PTR [rbp+rcx], xmm1
	paddq	xmm2, xmm4
	xor	ebp, 16
	mov	eax, ebp
	xor	rax, 32
	movdqu	xmm0, XMMWORD PTR [rbp+rcx]
	movdqu	XMMWORD PTR [rbp+rcx], xmm2
	paddq	xmm0, xmm10
	movdqu	XMMWORD PTR [rax+rcx], xmm0
	movd rax, xmm3
	movdqa	xmm10, xmm8
	mov	QWORD PTR [r10+rcx], r15
	movdqa	xmm8, xmm5
	xor	r15, rax
	mov	QWORD PTR [r10+rcx+8], r13
	mov	r8d, r15d
	xor	r13, r9
	and	r8d, 2097136
	dec r11d
	jnz	CryptonightR_template_double_mainloop

 CryptonightR_template_double_part4:

 	mov	rbx, QWORD PTR [rsp+400]
	movaps	xmm6, XMMWORD PTR [rsp+160]
	movaps	xmm7, XMMWORD PTR [rsp+176]
	movaps	xmm8, XMMWORD PTR [rsp+192]
	movaps	xmm9, XMMWORD PTR [rsp+208]
	movaps	xmm10, XMMWORD PTR [rsp+224]
	movaps	xmm11, XMMWORD PTR [rsp+240]
	movaps	xmm12, XMMWORD PTR [rsp+256]
	movaps	xmm13, XMMWORD PTR [rsp+272]
	movaps	xmm14, XMMWORD PTR [rsp+288]
	movaps	xmm15, XMMWORD PTR [rsp+304]
	add	rsp, 320
	pop	r15
	pop	r14
	pop	r13
	pop	r12
	pop	rdi
	pop	rsi
	pop	rbp
	ret	0
CryptonightR_template_double_end:
  
410  src/crypto/asm/win64/cn2/cnv2_double_main_loop_sandybridge.inc
Large diffs are not rendered by default.

  
180  src/crypto/asm/win64/cn2/cnv2_main_loop_bulldozer.inc
@@ -0,0 +1,180 @@
	mov	QWORD PTR [rsp+16], rbx
	mov	QWORD PTR [rsp+24], rbp
	mov	QWORD PTR [rsp+32], rsi
	push	rdi
	push	r12
	push	r13
	push	r14
	push	r15
	sub	rsp, 64

 	stmxcsr DWORD PTR [rsp]
	mov DWORD PTR [rsp+4], 24448
	ldmxcsr DWORD PTR [rsp+4]

 	mov	rax, QWORD PTR [rcx+48]
	mov	r9, rcx
	xor	rax, QWORD PTR [rcx+16]
	mov	ebp, 524288
	mov	r8, QWORD PTR [rcx+32]
	xor	r8, QWORD PTR [rcx]
	mov	r11, QWORD PTR [rcx+40]
	mov	r10, r8
	mov	rdx, QWORD PTR [rcx+56]
	movd	xmm3, rax
	xor	rdx, QWORD PTR [rcx+24]
	xor	r11, QWORD PTR [rcx+8]
	mov	rbx, QWORD PTR [rcx+224]
	mov	rax, QWORD PTR [r9+80]
	xor	rax, QWORD PTR [r9+64]
	movd	xmm0, rdx
	mov	rcx, QWORD PTR [rcx+88]
	xor	rcx, QWORD PTR [r9+72]
	mov	rdi, QWORD PTR [r9+104]
	and	r10d, 2097136
	movaps	XMMWORD PTR [rsp+48], xmm6
	movd	xmm4, rax
	movaps	XMMWORD PTR [rsp+32], xmm7
	movaps	XMMWORD PTR [rsp+16], xmm8
	xorps	xmm8, xmm8
	mov ax, 1023
	shl rax, 52
	movd xmm7, rax
	mov	r15, QWORD PTR [r9+96]
	punpcklqdq xmm3, xmm0
	movd	xmm0, rcx
	punpcklqdq xmm4, xmm0

 	ALIGN(64)
cnv2_main_loop_bulldozer:
	movdqa	xmm5, XMMWORD PTR [r10+rbx]
	movd xmm6, r8
	pinsrq xmm6, r11, 1
	lea	rdx, QWORD PTR [r10+rbx]
	lea	r9, QWORD PTR [rdi+rdi]
	shl	rdi, 32

 	mov	ecx, r10d
	mov	eax, r10d
	xor	ecx, 16
	xor	eax, 32
	xor	r10d, 48
	aesenc	xmm5, xmm6
	movdqa	xmm2, XMMWORD PTR [rcx+rbx]
	movdqa	xmm1, XMMWORD PTR [rax+rbx]
	movdqa	xmm0, XMMWORD PTR [r10+rbx]
	paddq	xmm2, xmm3
	paddq	xmm1, xmm6
	paddq	xmm0, xmm4
	movdqa	XMMWORD PTR [rcx+rbx], xmm0
	movdqa	XMMWORD PTR [rax+rbx], xmm2
	movdqa	XMMWORD PTR [r10+rbx], xmm1

 	movaps	xmm1, xmm8
	mov	rsi, r15
	xor	rsi, rdi

 	mov edi, 1023
	shl rdi, 52

 	movd	r14, xmm5
	pextrq rax, xmm5, 1

 	movdqa	xmm0, xmm5
	pxor	xmm0, xmm3
	mov	r10, r14
	and	r10d, 2097136
	movdqa	XMMWORD PTR [rdx], xmm0
	xor	rsi, QWORD PTR [r10+rbx]
	lea	r12, QWORD PTR [r10+rbx]
	mov	r13, QWORD PTR [r10+rbx+8]

 	add	r9d, r14d
	or	r9d, -2147483647
	xor	edx, edx
	div	r9
	mov	eax, eax
	shl	rdx, 32
	lea	r15, [rax+rdx]
	lea	rax, [r14+r15]
	shr	rax, 12
	add	rax, rdi
	movd	xmm0, rax
	sqrtsd	xmm1, xmm0
	movd	rdi, xmm1
	test	rdi, 524287
	je	sqrt_fixup_bulldozer
	shr	rdi, 19

 sqrt_fixup_bulldozer_ret:
	mov	rax, rsi
	mul	r14
	movd xmm1, rax
	movd xmm0, rdx
	punpcklqdq xmm0, xmm1

 	mov	r9d, r10d
	mov	ecx, r10d
	xor	r9d, 16
	xor	ecx, 32
	xor	r10d, 48
	movdqa	xmm1, XMMWORD PTR [rcx+rbx]
	xor rdx, [rcx+rbx]
	xor rax, [rcx+rbx+8]
	movdqa	xmm2, XMMWORD PTR [r9+rbx]
	pxor xmm2, xmm0
	paddq xmm4, XMMWORD PTR [r10+rbx]
	paddq	xmm2, xmm3
	paddq	xmm1, xmm6
	movdqa	XMMWORD PTR [r9+rbx], xmm4
	movdqa	XMMWORD PTR [rcx+rbx], xmm2
	movdqa	XMMWORD PTR [r10+rbx], xmm1

 	movdqa	xmm4, xmm3
	add	r8, rdx
	add	r11, rax
	mov	QWORD PTR [r12], r8
	xor	r8, rsi
	mov	QWORD PTR [r12+8], r11
	mov	r10, r8
	xor	r11, r13
	and	r10d, 2097136
	movdqa	xmm3, xmm5
	dec	ebp
	jne	cnv2_main_loop_bulldozer

 	ldmxcsr DWORD PTR [rsp]
	movaps	xmm6, XMMWORD PTR [rsp+48]
	lea	r11, QWORD PTR [rsp+64]
	mov	rbx, QWORD PTR [r11+56]
	mov	rbp, QWORD PTR [r11+64]
	mov	rsi, QWORD PTR [r11+72]
	movaps	xmm8, XMMWORD PTR [r11-48]
	movaps	xmm7, XMMWORD PTR [rsp+32]
	mov	rsp, r11
	pop	r15
	pop	r14
	pop	r13
	pop	r12
	pop	rdi
	jmp cnv2_main_loop_bulldozer_endp

 sqrt_fixup_bulldozer:
	movd r9, xmm5
	add r9, r15
	dec	rdi
	mov edx, -1022
	shl rdx, 32
	mov	rax, rdi
	shr	rdi, 19
	shr	rax, 20
	mov	rcx, rdi
	sub	rcx, rax
	lea	rcx, [rcx+rdx+1]
	add	rax, rdx
	imul	rcx, rax
	sub	rcx, r9
	adc	rdi, 0
	jmp	sqrt_fixup_bulldozer_ret

 cnv2_main_loop_bulldozer_endp: