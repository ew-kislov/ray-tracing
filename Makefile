all: build
build:
	g++ src/*.cpp -o main -std=c++17 -Werror