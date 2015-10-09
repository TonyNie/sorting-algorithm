/*
 * Tony Nie (cloudnie@gmail.com)
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#include "sort.h"

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

int data4[2][5] = {
	{1, 2, 3, 4, 5},
	{1, 2, 3, 4, 5},
};

typedef int (*sort_func)(int *, int);

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

static void test_sort(sort_func f)
{
	int ret = 0;


	ret = __test_sort(f, data1[0], data1[1],
			sizeof(data1[0]) / sizeof(data1[0][0]));

	assert(!ret);

	ret = __test_sort(f, data2[0], data2[1],
			sizeof(data2[0]) / sizeof(data2[0][0]));

	assert(!ret);

	ret = __test_sort(f, data3[0], data3[1],
			sizeof(data3[0]) / sizeof(data3[0][0]));

	ret = __test_sort(f, data4[0], data4[1],
			sizeof(data4[0]) / sizeof(data4[0][0]));

	assert(!ret);
}

int main(int argc, char **argv)
{
	test_sort(bubble_sort);
	test_sort(selection_sort);
	test_sort(insertion_sort);
	return 0;
}
