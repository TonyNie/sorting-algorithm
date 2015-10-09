/*
 * Tony Nie (cloudnie@gmail.com)
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

int selection_sort(int *buf, int len)
{
	int i = 0, j =0;

	for(i = 0; i < len; i++) {
		int min = i;
		for(j = i + 1; j < len; j++) {
			if (buf[j] < buf[min])
				min = j;
		}

		if (min != i) {
			int tmp = buf[i];
			buf[i] = buf[min];
			buf[min] = tmp;
		}

	}

	return 0;
}

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

int insertion_sort(int *buf, int len)
{
	int i = 0;

	for(i = 1; i < len; i++) {
		int j = 0;
		int s = buf[i];

		for(j = i - 1; j >= 0; j--) {
			if (s < buf[j])
				buf[j + 1] = buf[j];
			else
				break;
		}

		buf[j + 1] = s;
	}

	return 0;
}
