CC = gcc
CFLAGS = -Wall -g -std=c99


prgm:
	$(CC) $(CFLAGS) ./src/main.c ./src/linkedList.c ./src/file.c ./src/cars.c ./include/*.h  -Iinclude -o ./bin/runMe


test:
	$(CC) $(CFLAGS) ./src/testMain.c ./src/testInt.c ./src/linkedList.c ./include/*.h  -Iinclude -o ./bin/test


clean:
	rm ./bin/* 
