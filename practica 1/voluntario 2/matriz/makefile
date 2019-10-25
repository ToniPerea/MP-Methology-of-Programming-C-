BIN=./bin
SRC=./src
INC=./include
LIB=./lib
OBJ=./obj

TARGET = matriz
CXX = G++
CFLAGS = -std=c++11 -w


all: lib/utilidades obj/matriz
	g++ $(CXXFLAGS) $(SRC)/main.cpp $(OBJ)/matriz.o -o $(BIN)/$(TARGET) -I$(INC) -L$(LIB)  -lutilidades

obj/matriz:
	g++ $(CXXFLAGS) -c -o $(OBJ)/matriz.o $(SRC)/matriz.cpp -I$(INC) 

obj/utilidades:
	g++ $(CXXFLAGS) -c -o $(OBJ)/utilidades.o -I$(INC) $(SRC)/utilidades.cpp

lib/utilidades: obj/utilidades
	ar rvs $(LIB)/libutilidades.a $(OBJ)/utilidades.o

init:
	@mkdir bin docs src include lib obj

clean:
	@echo "Limpiando ejecutables y objetos"
	@rm -rf ./obj/*
	@rm -rf ./bin/*
	@rm -rf ./lib/*
	@rm -rf ./docs/*