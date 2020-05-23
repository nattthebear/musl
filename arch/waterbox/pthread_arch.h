extern struct pthread *__wbx_fake_pthread;

static inline struct pthread *__pthread_self()
{
	return __wbx_fake_pthread;
}

#define TP_ADJ(p) (p)

#define MC_PC gregs[REG_RIP]
