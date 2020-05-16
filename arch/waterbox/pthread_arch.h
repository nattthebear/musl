static inline struct pthread *__pthread_self()
{
	return (void *)-1;
}

#define TP_ADJ(p) (p)

#define MC_PC gregs[REG_RIP]
