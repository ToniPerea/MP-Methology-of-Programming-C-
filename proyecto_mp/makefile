all: ejecutable

ejecutable: imagen.o utilidades.o libutilidades
	@g++ -o ./bin/ejecutable ./obj/imagen.o ./src/main.cpp -I./include -L./lib  -lutilidades

imagen.o:
	@g++ -c -o ./obj/imagen.o ./src/imagen.cpp -I./include

utilidades.o:
	@g++ -c -o ./obj/utilidades.o ./src/utilidades.cpp -I./include

libutilidades: utilidades.o
	@ar rvs ./lib/libutilidades.a ./obj/utilidades.o


testImagen: imagen.o utilidades.o libutilidades
	@g++ -o ./bin/imagen_unit_test ./obj/imagen.o ./src/imagen_unit_test/imagen_unit_test.cpp -I./include -L./lib  -lutilidades
	./bin/imagen_unit_test


testUtilidades: imagen.o utilidades.o libutilidades
	@g++ -o ./bin/utilidades_unit_test ./obj/imagen.o ./src/utilidades_unit_test/utilidades_unit_test.cpp -I./include -L./lib  -lutilidades
	./bin/utilidades_unit_test

testIntegration: imagen.o utilidades.o libutilidades
	@g++ -o ./bin/integration_test ./obj/imagen.o ./src/integration_test/integration_test.cpp -I./include -L./lib  -lutilidades

docs: 
	@doxygen ./doc/doxyfile -o ./doc

clean:
	@rm -rf ./bin/* ./obj/* ./lib/*  ./doc/html/* ./doc/latex/*

exe: ejecutable
	@./bin/ejecutable 
	
