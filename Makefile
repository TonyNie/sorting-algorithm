CC=gcc


sort:sort.c test.c
	$(CC) -g -o $@ $^


clean:
	rm -rf *.o sort
