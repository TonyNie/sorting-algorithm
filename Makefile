CC=gcc


sort:sort.c
	$(CC) -g -o $@ $^


clean:
	rm -rf *.o sort
