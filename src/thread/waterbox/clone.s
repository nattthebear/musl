.text
.global __clone
.hidden __clone
.type   __clone,@function
__clone:
	/* syscall number - NR_WBX_CLONE */
	xor %eax,%eax
	mov $2000,%ax

	/* set up information on child stack */
	and $-16,%rsi /* align */
	sub $24,%rsi
	mov %rdi,16(%rsi) /* thread entry point */
	mov %rcx,8(%rsi) /* thread entry argument */
	lea child_thread_start(%rip),%r10
	mov %r10,(%rsi) /* host will ret in child thread... */
	sub $8,%rsi /* ... after popping 1 regs */

	mov %r9,%rdi /* tls */
	mov %r8,%rdx /* parent_tid */
	mov 8(%rsp),%rcx /* child_tid */

	/* syscall NR_WBX_CLONE (tls, child_rsp, parent_tid, child_tid) */
	mov $0x35f00000080,%r10
	call *%r10
	ret

child_thread_start:
	pop %rdi /* thread entry argument */
	mov 0(%rsp),%rax /* thread entry point (don't pop; fix stack alignment) */
	call *%rax /* run thread */

	/* syscall exit */
	mov $60,%al
	mov $0x35f00000080,%r10
	call *%r10
	int3
