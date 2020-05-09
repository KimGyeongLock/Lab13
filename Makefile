TARGET = book
DTARGET = book_debug
OBJECTS = book.o main.c saveload.o search.o
CFLAGS = -W -Wall
CC = gcc

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^

clean :
	rm *.o $(TARGET) $(DTARGET)


