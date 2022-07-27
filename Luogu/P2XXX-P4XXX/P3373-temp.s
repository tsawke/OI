	.file	"P3373-rewrite.cpp"
	.text
	.section	.rodata
	.type	_ZN6__pstl9execution2v1L3seqE, @object
	.size	_ZN6__pstl9execution2v1L3seqE, 1
_ZN6__pstl9execution2v1L3seqE:
	.zero	1
	.type	_ZN6__pstl9execution2v1L3parE, @object
	.size	_ZN6__pstl9execution2v1L3parE, 1
_ZN6__pstl9execution2v1L3parE:
	.zero	1
	.type	_ZN6__pstl9execution2v1L9par_unseqE, @object
	.size	_ZN6__pstl9execution2v1L9par_unseqE, 1
_ZN6__pstl9execution2v1L9par_unseqE:
	.zero	1
	.type	_ZN6__pstl9execution2v1L5unseqE, @object
	.size	_ZN6__pstl9execution2v1L5unseqE, 1
_ZN6__pstl9execution2v1L5unseqE:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZN4SegTC2Ev,"axG",@progbits,_ZN4SegTC5Ev,comdat
	.align 2
	.weak	_ZN4SegTC2Ev
	.type	_ZN4SegTC2Ev, @function
_ZN4SegTC2Ev:
.LFB4383:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-8(%rbp), %rax
	movq	$1, 16(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4383:
	.size	_ZN4SegTC2Ev, .-_ZN4SegTC2Ev
	.weak	_ZN4SegTC1Ev
	.set	_ZN4SegTC1Ev,_ZN4SegTC2Ev
	.globl	segT
	.bss
	.align 32
	.type	segT, @object
	.size	segT, 10560000
segT:
	.zero	10560000
	.globl	N
	.align 4
	.type	N, @object
	.size	N, 4
N:
	.zero	4
	.globl	M
	.align 4
	.type	M, @object
	.size	M, 4
M:
	.zero	4
	.globl	MOD
	.align 8
	.type	MOD, @object
	.size	MOD, 8
MOD:
	.zero	8
	.text
	.globl	_Z7MakeModi
	.type	_Z7MakeModi, @function
_Z7MakeModi:
.LFB4385:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	(%rax), %rax
	movq	MOD(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	%rcx, (%rax)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	(%rax), %rax
	movq	MOD(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	%rcx, (%rax)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	(%rax), %rax
	movq	MOD(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	%rcx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4385:
	.size	_Z7MakeModi, .-_Z7MakeModi
	.section	.rodata
.LC0:
	.string	"%lld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB4386:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	call	_Z4readIiET_v
	movl	%eax, N(%rip)
	call	_Z4readIiET_v
	movl	%eax, M(%rip)
	call	_Z4readIxET_v
	movq	%rax, MOD(%rip)
	movl	N(%rip), %eax
	movl	%eax, %edx
	movl	$1, %esi
	movl	$1, %edi
	call	_Z5Buildiii
	movl	$1, -4(%rbp)
	jmp	.L4
.L9:
	call	_Z4readIiET_v
	movl	%eax, -8(%rbp)
	cmpl	$3, -8(%rbp)
	je	.L5
	cmpl	$3, -8(%rbp)
	jg	.L6
	cmpl	$1, -8(%rbp)
	je	.L7
	cmpl	$2, -8(%rbp)
	je	.L8
	jmp	.L6
.L7:
	call	_Z4readIiET_v
	movl	%eax, -36(%rbp)
	call	_Z4readIiET_v
	movl	%eax, -40(%rbp)
	call	_Z4readIxET_v
	movq	%rax, -48(%rbp)
	movl	N(%rip), %eax
	movq	-48(%rbp), %rsi
	movl	-40(%rbp), %ecx
	movl	-36(%rbp), %edx
	movq	%rsi, %r9
	movl	%ecx, %r8d
	movl	%edx, %ecx
	movl	%eax, %edx
	movl	$1, %esi
	movl	$1, %edi
	call	_Z9UpdateMuliiiiix
	jmp	.L6
.L8:
	call	_Z4readIiET_v
	movl	%eax, -20(%rbp)
	call	_Z4readIiET_v
	movl	%eax, -24(%rbp)
	call	_Z4readIxET_v
	movq	%rax, -32(%rbp)
	movl	N(%rip), %eax
	movq	-32(%rbp), %rsi
	movl	-24(%rbp), %ecx
	movl	-20(%rbp), %edx
	movq	%rsi, %r9
	movl	%ecx, %r8d
	movl	%edx, %ecx
	movl	%eax, %edx
	movl	$1, %esi
	movl	$1, %edi
	call	_Z9UpdateAddiiiiix
	jmp	.L6
.L5:
	call	_Z4readIiET_v
	movl	%eax, -12(%rbp)
	call	_Z4readIiET_v
	movl	%eax, -16(%rbp)
	movl	N(%rip), %eax
	movl	-16(%rbp), %ecx
	movl	-12(%rbp), %edx
	movl	%ecx, %r8d
	movl	%edx, %ecx
	movl	%eax, %edx
	movl	$1, %esi
	movl	$1, %edi
	call	_Z5Queryiiiii
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	nop
.L6:
	addl	$1, -4(%rbp)
.L4:
	movl	M(%rip), %eax
	cmpl	%eax, -4(%rbp)
	jle	.L9
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4386:
	.size	main, .-main
	.globl	_Z5Buildiii
	.type	_Z5Buildiii, @function
_Z5Buildiii:
.LFB4387:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	-24(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jne	.L12
	call	_Z4readIiET_v
	cltq
	movq	MOD(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	%rcx, (%rax)
	jmp	.L11
.L12:
	movl	-24(%rbp), %edx
	movl	-28(%rbp), %eax
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -4(%rbp)
	movl	-20(%rbp), %eax
	leal	(%rax,%rax), %ecx
	movl	-4(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	movl	%ecx, %edi
	call	_Z5Buildiii
	movl	-4(%rbp), %eax
	leal	1(%rax), %esi
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	leal	1(%rax), %ecx
	movl	-28(%rbp), %eax
	movl	%eax, %edx
	movl	%ecx, %edi
	call	_Z5Buildiii
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	(%rax), %rcx
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	(%rax), %rax
	addq	%rcx, %rax
	movq	MOD(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	%rcx, (%rax)
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4387:
	.size	_Z5Buildiii, .-_Z5Buildiii
	.globl	_Z8PushDowniii
	.type	_Z8PushDowniii, @function
_Z8PushDowniii:
.LFB4388:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	-24(%rbp), %eax
	cmpl	-28(%rbp), %eax
	je	.L18
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L17
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	(%rax), %rax
	cmpq	$1, %rax
	je	.L19
.L17:
	movl	-24(%rbp), %edx
	movl	-28(%rbp), %eax
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -4(%rbp)
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	(%rax), %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	(%rax), %rax
	imulq	%rax, %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	(%rax), %rdx
	movl	-4(%rbp), %eax
	subl	-24(%rbp), %eax
	addl	$1, %eax
	cltq
	imulq	%rdx, %rax
	addq	%rcx, %rax
	movq	MOD(%rip), %rcx
	movl	-20(%rbp), %edx
	leal	(%rdx,%rdx), %esi
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movslq	%esi, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	%rcx, (%rax)
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	(%rax), %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	(%rax), %rax
	imulq	%rax, %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	(%rax), %rdx
	movl	-4(%rbp), %eax
	leal	1(%rax), %esi
	movl	-28(%rbp), %eax
	subl	%esi, %eax
	addl	$1, %eax
	cltq
	imulq	%rdx, %rax
	addq	%rcx, %rax
	movq	MOD(%rip), %rcx
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	leal	1(%rdx), %esi
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movslq	%esi, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	%rcx, (%rax)
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	(%rax), %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	(%rax), %rax
	imulq	%rcx, %rax
	movq	MOD(%rip), %rcx
	movl	-20(%rbp), %edx
	leal	(%rdx,%rdx), %esi
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movslq	%esi, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	%rcx, (%rax)
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	(%rax), %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	(%rax), %rax
	imulq	%rcx, %rax
	movq	MOD(%rip), %rcx
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	leal	1(%rdx), %esi
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movslq	%esi, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	%rcx, (%rax)
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	(%rax), %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	(%rax), %rax
	imulq	%rcx, %rax
	movq	MOD(%rip), %rcx
	movl	-20(%rbp), %edx
	leal	(%rdx,%rdx), %esi
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movslq	%esi, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	%rcx, (%rax)
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	(%rax), %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	(%rax), %rax
	imulq	%rcx, %rax
	movq	MOD(%rip), %rcx
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	leal	1(%rdx), %esi
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movslq	%esi, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	%rcx, (%rax)
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	(%rax), %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	(%rax), %rax
	addq	%rcx, %rax
	movq	MOD(%rip), %rcx
	movl	-20(%rbp), %edx
	leal	(%rdx,%rdx), %esi
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movslq	%esi, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	%rcx, (%rax)
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	(%rax), %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	(%rax), %rax
	addq	%rcx, %rax
	movq	MOD(%rip), %rcx
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	leal	1(%rdx), %esi
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movslq	%esi, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	%rcx, (%rax)
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	$0, (%rax)
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	$1, (%rax)
	jmp	.L14
.L18:
	nop
	jmp	.L14
.L19:
	nop
.L14:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4388:
	.size	_Z8PushDowniii, .-_Z8PushDowniii
	.globl	_Z9UpdateAddiiiiix
	.type	_Z9UpdateAddiiiiix, @function
_Z9UpdateAddiiiiix:
.LFB4389:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	%ecx, -32(%rbp)
	movl	%r8d, -36(%rbp)
	movq	%r9, -48(%rbp)
	movl	-24(%rbp), %edx
	movl	-28(%rbp), %eax
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -4(%rbp)
	movl	-24(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jg	.L25
	movl	-28(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L25
	movl	-32(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jg	.L24
	movl	-28(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jg	.L24
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	(%rax), %rdx
	movl	-28(%rbp), %eax
	subl	-24(%rbp), %eax
	addl	$1, %eax
	cltq
	imulq	-48(%rbp), %rax
	addq	%rdx, %rax
	movq	MOD(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	%rcx, (%rax)
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	(%rax), %rdx
	movq	-48(%rbp), %rax
	addq	%rdx, %rax
	movq	MOD(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	%rcx, (%rax)
	jmp	.L20
.L24:
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %ecx
	movl	-20(%rbp), %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	_Z8PushDowniii
	movl	-20(%rbp), %eax
	leal	(%rax,%rax), %edi
	movq	-48(%rbp), %r8
	movl	-36(%rbp), %esi
	movl	-32(%rbp), %ecx
	movl	-4(%rbp), %edx
	movl	-24(%rbp), %eax
	movq	%r8, %r9
	movl	%esi, %r8d
	movl	%eax, %esi
	call	_Z9UpdateAddiiiiix
	movl	-4(%rbp), %eax
	leal	1(%rax), %esi
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	leal	1(%rax), %edi
	movq	-48(%rbp), %r8
	movl	-36(%rbp), %ecx
	movl	-32(%rbp), %edx
	movl	-28(%rbp), %eax
	movq	%r8, %r9
	movl	%ecx, %r8d
	movl	%edx, %ecx
	movl	%eax, %edx
	call	_Z9UpdateAddiiiiix
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	(%rax), %rcx
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	(%rax), %rax
	addq	%rcx, %rax
	movq	MOD(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	%rcx, (%rax)
	jmp	.L20
.L25:
	nop
.L20:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4389:
	.size	_Z9UpdateAddiiiiix, .-_Z9UpdateAddiiiiix
	.globl	_Z9UpdateMuliiiiix
	.type	_Z9UpdateMuliiiiix, @function
_Z9UpdateMuliiiiix:
.LFB4390:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	%ecx, -32(%rbp)
	movl	%r8d, -36(%rbp)
	movq	%r9, -48(%rbp)
	movl	-24(%rbp), %edx
	movl	-28(%rbp), %eax
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -4(%rbp)
	movl	-24(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jg	.L31
	movl	-28(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L31
	movl	-32(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jg	.L30
	movl	-28(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jg	.L30
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	(%rax), %rax
	imulq	-48(%rbp), %rax
	movq	MOD(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	%rcx, (%rax)
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	(%rax), %rax
	imulq	-48(%rbp), %rax
	movq	MOD(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	%rcx, (%rax)
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	(%rax), %rax
	imulq	-48(%rbp), %rax
	movq	MOD(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	%rcx, (%rax)
	jmp	.L26
.L30:
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %ecx
	movl	-20(%rbp), %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	_Z8PushDowniii
	movl	-20(%rbp), %eax
	leal	(%rax,%rax), %edi
	movq	-48(%rbp), %r8
	movl	-36(%rbp), %esi
	movl	-32(%rbp), %ecx
	movl	-4(%rbp), %edx
	movl	-24(%rbp), %eax
	movq	%r8, %r9
	movl	%esi, %r8d
	movl	%eax, %esi
	call	_Z9UpdateMuliiiiix
	movl	-4(%rbp), %eax
	leal	1(%rax), %esi
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	leal	1(%rax), %edi
	movq	-48(%rbp), %r8
	movl	-36(%rbp), %ecx
	movl	-32(%rbp), %edx
	movl	-28(%rbp), %eax
	movq	%r8, %r9
	movl	%ecx, %r8d
	movl	%edx, %ecx
	movl	%eax, %edx
	call	_Z9UpdateMuliiiiix
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	(%rax), %rcx
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	(%rax), %rax
	addq	%rcx, %rax
	movq	MOD(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rcx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	%rcx, (%rax)
	jmp	.L26
.L31:
	nop
.L26:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4390:
	.size	_Z9UpdateMuliiiiix, .-_Z9UpdateMuliiiiix
	.globl	_Z5Queryiiiii
	.type	_Z5Queryiiiii, @function
_Z5Queryiiiii:
.LFB4391:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movl	%edi, -36(%rbp)
	movl	%esi, -40(%rbp)
	movl	%edx, -44(%rbp)
	movl	%ecx, -48(%rbp)
	movl	%r8d, -52(%rbp)
	movl	-40(%rbp), %edx
	movl	-44(%rbp), %eax
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -20(%rbp)
	movl	-40(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jg	.L33
	movl	-44(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jge	.L34
.L33:
	movl	$0, %eax
	jmp	.L35
.L34:
	movl	-48(%rbp), %eax
	cmpl	-40(%rbp), %eax
	jg	.L36
	movl	-44(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jg	.L36
	movl	-36(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	(%rax), %rax
	jmp	.L35
.L36:
	movl	-44(%rbp), %edx
	movl	-40(%rbp), %ecx
	movl	-36(%rbp), %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	_Z8PushDowniii
	movl	-36(%rbp), %eax
	leal	(%rax,%rax), %edi
	movl	-52(%rbp), %esi
	movl	-48(%rbp), %ecx
	movl	-20(%rbp), %edx
	movl	-40(%rbp), %eax
	movl	%esi, %r8d
	movl	%eax, %esi
	call	_Z5Queryiiiii
	movq	MOD(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rbx
	movl	-20(%rbp), %eax
	leal	1(%rax), %esi
	movl	-36(%rbp), %eax
	addl	%eax, %eax
	leal	1(%rax), %edi
	movl	-52(%rbp), %ecx
	movl	-48(%rbp), %edx
	movl	-44(%rbp), %eax
	movl	%ecx, %r8d
	movl	%edx, %ecx
	movl	%eax, %edx
	call	_Z5Queryiiiii
	movq	MOD(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rax
	addq	%rbx, %rax
	movq	MOD(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rax
.L35:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4391:
	.size	_Z5Queryiiiii, .-_Z5Queryiiiii
	.section	.rodata
.LC1:
	.string	"\nPrintSegTree[]: "
.LC2:
	.string	"[%lld---%lld&%lld]  "
	.text
	.globl	_Z11DescSegTreei
	.type	_Z11DescSegTreei, @function
_Z11DescSegTreei:
.LFB4392:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	$.LC1, %edi
	call	puts
	movl	$1, -4(%rbp)
	movl	$1, -8(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L38
.L39:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+16, %rax
	movq	(%rax), %rcx
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$segT+8, %rax
	movq	(%rax), %rdx
	movl	-4(%rbp), %eax
	movslq	%eax, %rsi
	movq	%rsi, %rax
	addq	%rax, %rax
	addq	%rsi, %rax
	salq	$3, %rax
	addq	$segT, %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -12(%rbp)
	addl	$1, -4(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jne	.L38
	movl	$10, %edi
	call	putchar
	sall	-8(%rbp)
	movl	$0, -12(%rbp)
.L38:
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	cmpl	%eax, -4(%rbp)
	jle	.L39
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4392:
	.size	_Z11DescSegTreei, .-_Z11DescSegTreei
	.section	.text._Z4readIiET_v,"axG",@progbits,_Z4readIiET_v,comdat
	.weak	_Z4readIiET_v
	.type	_Z4readIiET_v, @function
_Z4readIiET_v:
.LFB4719:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movw	$1, -6(%rbp)
	call	getchar
	movb	%al, -7(%rbp)
	jmp	.L41
.L43:
	cmpb	$45, -7(%rbp)
	jne	.L42
	movw	$-1, -6(%rbp)
.L42:
	call	getchar
	movb	%al, -7(%rbp)
.L41:
	cmpb	$47, -7(%rbp)
	jle	.L43
	cmpb	$57, -7(%rbp)
	jg	.L43
	jmp	.L44
.L46:
	movl	-4(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, -4(%rbp)
	movsbl	-7(%rbp), %eax
	subl	$48, %eax
	addl	%eax, -4(%rbp)
	call	getchar
	movb	%al, -7(%rbp)
.L44:
	cmpb	$47, -7(%rbp)
	jle	.L45
	cmpb	$57, -7(%rbp)
	jle	.L46
.L45:
	movswl	-6(%rbp), %eax
	movl	-4(%rbp), %edx
	imull	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4719:
	.size	_Z4readIiET_v, .-_Z4readIiET_v
	.section	.text._Z4readIxET_v,"axG",@progbits,_Z4readIxET_v,comdat
	.weak	_Z4readIxET_v
	.type	_Z4readIxET_v, @function
_Z4readIxET_v:
.LFB4720:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	$0, -8(%rbp)
	movw	$1, -10(%rbp)
	call	getchar
	movb	%al, -11(%rbp)
	jmp	.L49
.L51:
	cmpb	$45, -11(%rbp)
	jne	.L50
	movw	$-1, -10(%rbp)
.L50:
	call	getchar
	movb	%al, -11(%rbp)
.L49:
	cmpb	$47, -11(%rbp)
	jle	.L51
	cmpb	$57, -11(%rbp)
	jg	.L51
	jmp	.L52
.L54:
	movq	-8(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rax, %rax
	movq	%rax, -8(%rbp)
	movsbl	-11(%rbp), %eax
	subl	$48, %eax
	cltq
	addq	%rax, -8(%rbp)
	call	getchar
	movb	%al, -11(%rbp)
.L52:
	cmpb	$47, -11(%rbp)
	jle	.L53
	cmpb	$57, -11(%rbp)
	jle	.L54
.L53:
	movswq	-10(%rbp), %rax
	movq	-8(%rbp), %rdx
	imulq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4720:
	.size	_Z4readIxET_v, .-_Z4readIxET_v
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB5010:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	cmpl	$1, -20(%rbp)
	jne	.L60
	cmpl	$65535, -24(%rbp)
	jne	.L60
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
	movl	$segT, %eax
	movl	$439999, %ebx
	movq	%rax, %r12
	jmp	.L58
.L59:
	movq	%r12, %rdi
	call	_ZN4SegTC1Ev
	addq	$24, %r12
	subq	$1, %rbx
.L58:
	testq	%rbx, %rbx
	jns	.L59
.L60:
	nop
	addq	$16, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5010:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_segT, @function
_GLOBAL__sub_I_segT:
.LFB5011:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5011:
	.size	_GLOBAL__sub_I_segT, .-_GLOBAL__sub_I_segT
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_segT
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 11.2.1 20210728 (Red Hat 11.2.1-1)"
	.section	.note.GNU-stack,"",@progbits
