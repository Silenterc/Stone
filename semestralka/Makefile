#CREDIT FOR THE BASE OF THIS MAKEFILE GOES TO RADEK HUSEK, 
#https://gitlab.fit.cvut.cz/husekrad/pa2-cvika-2022/blob/master/cv10/semestralka/Makefile
LOGIN = zimaluk1
CXX = g++
BASIC_FLAGS = -std=c++17 -O2 -g -Wall -pedantic  
FLAGS = -fsanitize=address

SOURCES = $(wildcard src/*.cpp src/*/*.cpp)
OBJECTS = $(patsubst src/%.cpp, build/%.o, ${SOURCES})
DEPS = $(patsubst src/%.cpp, build/%.dep, ${SOURCES})

.PHONY: fast fast-debug all compile run valgrind clean count #these are goals, not files
fast: 
	${MAKE} -j12 compile #compilation on 12 threads

fast-debug: 
	${MAKE} -j12 debug
all: compile run

debug: BASIC_FLAGS += ${FLAGS}
debug: compile
compile: ${LOGIN}

${LOGIN}: ${OBJECTS}
	@mkdir -p build/
	@mkdir -p build/Effects/
	${CXX} ${BASIC_FLAGS} $^ -o $@ -lstdc++fs

build/%.o: src/%.cpp 
	@mkdir -p build/
	@mkdir -p build/Effects/
	${CXX} ${BASIC_FLAGS} -c $< -o $@ 

run: compile
	./${LOGIN}

valgrind: compile
	valgrind --leak-check=full ./${LOGIN}
clean: 
	rm -rf build 
	
	


