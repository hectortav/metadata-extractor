OBJS	= extractor.o
SOURCE	= extractor.c
HEADER	= extractor.h
SHARED  = _extractor.so
OUT	= extractor
CC	 = gcc
FLAGS	 = -O3 -g -c -Wall -fPIC
LFLAGS	 = -lcurl

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
	$(CC) -shared -usb -o $(SHARED) $(OBJS) $(LFLAGS)

extractor.o: extractor.c
	$(CC) $(FLAGS) extractor.c 

clean:
	rm -f $(OBJS) $(OUT) $(SHARED)
