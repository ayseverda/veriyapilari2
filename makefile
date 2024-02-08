all: derle bagla calistir

derle:
	g++ -I ./include -o ./lib/main.o -c ./src/main.cpp
	g++ -I ./include -o ./lib/avltree.o -c ./src/avltree.cpp
	g++ -I ./include -o ./lib/yigin.o -c ./src/yigin.cpp
	g++ -I ./include -o ./lib/yigindugumu.o -c ./src/yigindugumu.cpp

bagla:
	g++ -o ./bin/program.exe ./lib/yigin.o ./lib/main.o ./lib/avltree.o ./lib/yigindugumu.o

calistir:
	./bin/program
