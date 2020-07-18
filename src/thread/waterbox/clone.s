.text
.global __clone
.hidden __clone
.type   __clone,@function
__clone:
	; syscall number - NR_WBX_CLONE
	xor %eax,%eax
	mov $2000,%ax

	; set up information on child stack
	and $-16,%rsi ; align
	sub $32,%rsi
	mov %rdi,16(%rsi) ; thread entry point
	mov %rcx,8(%rsi) ; thread entry argument
	movq child_thread_start,(%rsi) ; host will immediately ret in child thread

	mov %r9,%rdi ; tls
	mov %r8,%rdx ; parent_tid
	mov 8(%rsp),%rcx ; child_tid

	; syscall NR_WBX_CLONE (tls, child_rsp, parent_tid, child_tid)
	mov $0x35f00000080,%r10
	call *%r10
	ret

child_thread_start:
	pop %rdi ; thread entry argument
	pop %rax ; thread entry point
	call *%rax ; run thread

	; syscall exit
	mov $60,%al
	mov $0x35f00000080,%r10
	call *%r10
	int3
