#include <stdlib.h>
#include <lkmm.h>
#include <pthread.h>
#include <assert.h>

int x;
int y;
int z;

void *P0(void *unused)
{
	WRITE_ONCE(x, 1);
	WRITE_ONCE(y, 1);
}

void *P1(void *unused)
{
	int r0;

	r0 = READ_ONCE(y);
	WRITE_ONCE(z, 1);
}

void *P2(void *unused)
{
	int r0;
	int r1;

	r0 = READ_ONCE(z);
	r1 = READ_ONCE(x);
}

int main()
{
	pthread_t t0, t1, t2;

	pthread_create(&t0, NULL, P0, NULL);
	pthread_create(&t1, NULL, P1, NULL);
	pthread_create(&t2, NULL, P2, NULL);

	return 0;
}
