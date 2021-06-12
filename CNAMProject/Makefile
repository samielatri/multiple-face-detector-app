CC = g++
CFLAGS = -g -Wall
SRCS = Reader.cpp
PROG = Reader

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
