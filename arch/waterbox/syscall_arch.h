#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

extern long (*__wsyscall0)(long);
static __inline long __syscall0(long n)
{
	return __wsyscall0(n);
}

extern long (*__wsyscall1)(long, long);
static __inline long __syscall1(long n, long a1)
{
	return __wsyscall1(n, a1);
}

extern long (*__wsyscall2)(long, long, long);
static __inline long __syscall2(long n, long a1, long a2)
{
	return __wsyscall2(n, a1, a2);
}

extern long (*__wsyscall3)(long, long, long, long);
static __inline long __syscall3(long n, long a1, long a2, long a3)
{
	return __wsyscall3(n, a1, a2, a3);
}

extern long (*__wsyscall4)(long, long, long, long, long);
static __inline long __syscall4(long n, long a1, long a2, long a3, long a4)
{
	return __wsyscall4(n, a1, a2, a3, a4);
}

extern long (*__wsyscall5)(long, long, long, long, long, long);
static __inline long __syscall5(long n, long a1, long a2, long a3, long a4, long a5)
{
	return __wsyscall5(n, a1, a2, a3, a4, a5);
}

extern long (*__wsyscall6)(long, long, long, long, long, long, long);
static __inline long __syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
	return __wsyscall6(n, a1, a2, a3, a4, a5, a6);
}

#define VDSO_USEFUL
#define VDSO_CGT_SYM "__vdso_clock_gettime"
#define VDSO_CGT_VER "LINUX_2.6"
#define VDSO_GETCPU_SYM "__vdso_getcpu"
#define VDSO_GETCPU_VER "LINUX_2.6"

#define IPC_64 0
