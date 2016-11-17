CC = g++
CFLAGS = -c -Wall -Wno-write-strings

INCDIRS = -I../../include

OBJS = edge.o graph.o vertex.o
TGT = libgraph.a

all: $(OBJS)
	ar -r $(TGT) $(OBJS)

clean:
	rm -f $(TGT) $(OBJS)

wc: clean
	wc -l *.cc

.cc.o: $<
	$(CC) $(CFLAGS) $(INCDIRS) -o $@ $<
