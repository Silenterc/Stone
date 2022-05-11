LOGIN = zimaluk1
CXX = g++
BASIC_FLAGS = -std=c++17 -O2 -g -Wall -pedantic  
FLAGS = -fsanitize=address

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp, build/%.o, ${SOURCES})
DEPS = $(patsubst src/%.cpp, build/%.dep, ${SOURCES})

.PHONY: all compile run valgrind clean


all: compile doc

compile: ${LOGIN}

${LOGIN}: ${OBJECTS}
	@mkdir -p build/
	${CXX} ${BASIC_FLAGS} $^ -o $@ -lstdc++fs

build/%.o: src/%.cpp 
	@mkdir -p build/
	${CXX} ${BASIC_FLAGS} -c $< -o $@ 

run: compile
	./${LOGIN}

valgrind: compile
	valgrind ./${LOGIN}
clean: 
	rm -rf build 


