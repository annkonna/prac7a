CC = gcc
CFLAGS = -g

empget: empget.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm empget

.PHONY: empget
