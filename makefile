CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14
S = Star
P = Planet
V = Vector
I = List
L = program1

all: $(S).o $(L).o $(P).o $(V).o $(I).o 
	g++ $(V).o $(I).o $(S).o $(L).o $(P).o -o $(L)

$(P).o:	$(P).cpp
	g++ -c $(CFLAGS) $(P).cpp -o $(P).o

$(I).o:	$(I).cpp
	g++ -c $(CFLAGS) $(I).cpp -o $(I).o

$(V).o:	$(V).cpp
	g++ -c $(CFLAGS) $(V).cpp -o $(V).o

$(S).o:	$(S).cpp
	g++ -c $(CFLAGS) $(S).cpp -o $(S).o

$(L).o:
	g++ -c $(CFLAGS) $(L).cpp -o $(L).o

run: all
	./$(L)

memcheck: all
	valgrind ./$(L)

clean:
	rm $(L) *.o
