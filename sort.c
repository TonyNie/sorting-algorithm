#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

int data1[2][1] = {
	{100},
	{100},
};

int data2[2][2] = {
	{100, 8},
	{8, 100},
};

int data3[2][5] = {
	{10, 2, 7, 100, 1},
	{1, 2, 7, 10, 100},
};

typedef int (*sort_func)(int *, int);

int bubble_sort(int *buf, int len)
{
	int i = 0, j = 0;

	for (i = len - 1; i > 0; i--) {
		for(j = 1; j <= i; j++) {
			if (buf[j - 1] > buf[j]) {
				int tmp = buf[j];
				buf[j] = buf[j - 1];
				buf[j - 1] = tmp;
			}
		}
	}	

	return 0;
}


static int __test_sort(sort_func f, int *__buf, int *res, int len)
{
	int *buf = malloc(len * sizeof(*__buf));

	if (!buf)
		return -ENOMEM;

	memcpy(buf, __buf, len * sizeof(*buf));
	f(buf, len);

	if (!memcmp(buf, res, len * sizeof(*buf)))
		return 0;
	else 
		return -1;

	if (buf)
		free(buf);

	return 0;
}

static void test_sort()
{
	int ret = 0;


	ret = __test_sort(bubble_sort, data1[0], data1[1],
			sizeof(data1[0]) / sizeof(data1[0][0]));

	assert(!ret);

	ret = __test_sort(bubble_sort, data2[0], data2[1],
			sizeof(data2[0]) / sizeof(data2[0][0]));

	assert(!ret);

	ret = __test_sort(bubble_sort, data3[0], data3[1],
			sizeof(data3[0]) / sizeof(data3[0][0]));

	assert(!ret);
}

int main(int argc, char **argv)
{
	test_sort();
	return 0;
}
