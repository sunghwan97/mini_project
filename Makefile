CC = gcc
CFlags = -W -Wall
TARGET = shop
DTARGET = shop_debug
OBJECTS = product.o manager.o market.c

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^

clean : 
	rm *.o $(TARGET) $(DTARGET)
