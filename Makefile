OBJS	= extractor.o
SOURCE	= extractor.c
HEADER	= extractor.h
OUT	= extractor
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = -lcurl

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

extractor.o: extractor.c
	$(CC) $(FLAGS) extractor.c 

clean:
	rm -f $(OBJS) $(OUT)
