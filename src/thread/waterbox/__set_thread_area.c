#include "pthread_impl.h"

extern struct pthread *__wbx_fake_pthread;

int __set_thread_area(void *p)
{
	__wbx_fake_pthread = p;
	return 0;
}
