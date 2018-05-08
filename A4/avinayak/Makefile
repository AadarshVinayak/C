CC = gcc
CFLAGS = -Wall -g -std=c99


prgm:
	$(CC) $(CFLAGS) ./src/main.c ./src/hashTable.c ./src/dictionary.c ./src/readData.c ./include/*.h  -Iinclude -o ./bin/runMe 


test:
	$(CC) $(CFLAGS) ./src/test.c ./src/binarySearchTree.c ./src/integer.c ./include/BinarySearchTreeAPI.h ./include/Integer.h -Iinclude -o ./bin/test

clean:
	rm ./bin/* 
