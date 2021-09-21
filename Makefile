all: 
	gcc ./main.cpp -o build/main -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
	./build/main