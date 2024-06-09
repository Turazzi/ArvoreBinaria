CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic
TARGET = main
OBJS = main.o tree.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c tree.h
	$(CC) $(CFLAGS) -c main.c

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c

clean:
	rm -f $(TARGET) $(OBJS)
