CC = gcc
CFLAGS = -Wall -Wall
SRC_FILES = project3C.c project3C_hashtable.c
TARGET = project3C

all: $(TARGET)

$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)