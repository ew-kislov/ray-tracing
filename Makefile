all: build
build:
	g++ src/vector.cpp src/main.cpp -o main -std=c++17 -Werror