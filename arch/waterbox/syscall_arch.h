#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

struct __AddressRange {
	unsigned long start;
	unsigned long size;
};
struct __WbxSysLayout {
	struct __AddressRange elf;
	struct __AddressRange sbrk;
	struct __AddressRange sealed;
	struct __AddressRange invis;
	struct __AddressRange plain;
	struct __AddressRange mmap;
};
struct __WbxSysSyscall {
	long ud;
	void* syscall;
};
struct __WbxSysArea {
	struct __WbxSysLayout layout;
	struct __WbxSysSyscall syscall;
};
extern struct __WbxSysArea __wbxsysarea;

static __inline long __syscall0(long n)
{
	return ((long(*)(long, long))__wbxsysarea.syscall.syscall)(n, __wbxsysarea.syscall.ud);
}

static __inline long __syscall1(long n, long a1)
{
	return ((long(*)(long, long, long))__wbxsysarea.syscall.syscall)(n, __wbxsysarea.syscall.ud, a1);
}

static __inline long __syscall2(long n, long a1, long a2)
{
	return ((long(*)(long, long, long, long))__wbxsysarea.syscall.syscall)(n, __wbxsysarea.syscall.ud, a1, a2);
}

static __inline long __syscall3(long n, long a1, long a2, long a3)
{
	return ((long(*)(long, long, long, long, long))__wbxsysarea.syscall.syscall)(n, __wbxsysarea.syscall.ud, a1, a2, a3);
}

static __inline long __syscall4(long n, long a1, long a2, long a3, long a4)
{
	return ((long(*)(long, long, long, long, long, long))__wbxsysarea.syscall.syscall)(n, __wbxsysarea.syscall.ud, a1, a2, a3, a4);
}

static __inline long __syscall5(long n, long a1, long a2, long a3, long a4, long a5)
{
	return ((long(*)(long, long, long, long, long, long, long))__wbxsysarea.syscall.syscall)(n, __wbxsysarea.syscall.ud, a1, a2, a3, a4, a5);
}

static __inline long __syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
	return ((long(*)(long, long, long, long, long, long, long, long))__wbxsysarea.syscall.syscall)(n, __wbxsysarea.syscall.ud, a1, a2, a3, a4, a5, a6);
}

#define VDSO_USEFUL
#define VDSO_CGT_SYM "__vdso_clock_gettime"
#define VDSO_CGT_VER "LINUX_2.6"
#define VDSO_GETCPU_SYM "__vdso_getcpu"
#define VDSO_GETCPU_VER "LINUX_2.6"

#define IPC_64 0
