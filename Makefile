all: 
	gcc ./main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
	./main