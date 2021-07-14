	.file	"test.c"
	.text
	.section	.rodata
.LC0:
	.string	"hello world"
	.text
	.globl	print_hello
	.type	print_hello, @function
print_hello:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC0, %edi
	call	puts
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	print_hello, .-print_hello
	.ident	"GCC: (Uos 8.3.0.7-1+dde) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
