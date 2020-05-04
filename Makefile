TARGET = book
DTARGET = book_debug
OBJECTS = book.c saveload.o
CFLAGS = -W -Wall
CC = gcc

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^

clean :
	rm *.o $(TARGET) $(DTARGET)


