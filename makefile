Object1 = Definition.h Append.h DeleteChange.h Monthly.h Report.h Search.h Sort.h
Object2 = Definition.o Append.o DeleteChange.o Monthly.o Report.o Search.o Sort.o

all: Main

Main: Main.o $(Object2)
	g++ Main.o $(Object2) -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

Append.o: Append.cpp
	g++ -c Append.cpp

Delete&Change.o: DeleteChange.cpp
	g++ -c DeleteChange.cpp

Monthly.o: Monthly.cpp
	g++ -c Monthly.cpp

Report.o: Report.cpp
	g++ -c Report.cpp

Search.o: Search.cpp
	g++ -c Search.cpp

Sort.o: Sort.cpp Sort.h
	g++ -c Sort.cpp

Definition.o: Definition.cpp
	g++ -c Definition.cpp

clean:
	rm *.o Main
