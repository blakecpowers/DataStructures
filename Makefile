all:
	g++ -I../include -o list list.cc main.cc

clean:
	rm -f list
