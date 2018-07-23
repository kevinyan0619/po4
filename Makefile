all:	
	g++ -c CLOOK.cpp -o CLOOK.o
	g++ -c FIFO.cpp -o FIFO.o
	g++ -c fileReader.cpp -o fileReader.o
	g++ -c FLOOK.cpp -o FLOOK.o
	g++ -c LOOK.cpp -o LOOK.o
	g++ -c SSTF.cpp -o SSTF.o
	g++ -c main.cpp -o main.o
	g++ -o iosched main.o CLOOK.o FIFO.o LOOK.o FLOOK.o SSTF.o fileReader.o

clean:
	rm -rf *.o
	rm -rf iosched
