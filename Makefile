CC=g++
#LFLAGS=-o
#CFLAGS=-std=c++11 -Wall -s -O6 -c
CFLAGS=-Wall -g -c
CPPFLAGS=
RM=rm
TARGET=namegen

#DEBUGFLAGS=-DMSS
#DEBUGLIBS=-lmss

LIBS=

objects = namegen.o

all: namegen

namegen: $(objects)
	$(CC) -o $(TARGET) $(objects) $(LIBS) $(DEBUGLIBS)

clean:
	$(RM) $(objects)
