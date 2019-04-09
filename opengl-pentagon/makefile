all:pentagon

pentagon:main.o
	g++ -g -o pentagon main.o -lglut -lGLU -lGL

main.o:main.cpp
	g++ -c -g main.cpp

clean:
	rm -rf *.o pentagon