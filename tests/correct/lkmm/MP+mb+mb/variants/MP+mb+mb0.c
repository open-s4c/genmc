#include <stdlib.h>
#include <lkmm.h>
#include <pthread.h>
#include <assert.h>

int x;
int y;

void *P0(void *unused)
{
	WRITE_ONCE(x, 1);
	return NULL;
}

void *P1(void *unused)
{
	int r1; int r2;

	r1 = READ_ONCE(x);
	smp_mb();
	r2 = READ_ONCE(y);
	return NULL;
}

void *P2(void *unused)
{
	int r3;

	WRITE_ONCE(y, 1);
	smp_mb();
	r3 = READ_ONCE(x);
	return NULL;
}


int main()
{
	pthread_t t0, t1, t2;

	pthread_create(&t0, NULL, P0, NULL);
	pthread_create(&t1, NULL, P1, NULL);
	pthread_create(&t2, NULL, P2, NULL);

	return 0;
}
