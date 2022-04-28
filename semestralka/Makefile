LOGIN = zimaluk1
CXX = g++
BASIC_FLAGS = -std=c++17 -O2 -g -Wall -pedantic -fsanitize=address
FLAGS =

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp, build/%.o, ${SOURCES})
DEPS = $(patsubst src/%.cpp, build/%.dep, ${SOURCES})

.PHONY: all compile run 


all: compile doc

compile: ${LOGIN}

${LOGIN}: ${OBJECTS}
	@mkdir -p build/
	${CXX} ${BASIC_FLAGS} ${FLAGS} $^ -o $@

build/%.o: src/%.cpp 
	@mkdir -p build/
	${CXX} ${BASIC_FLAGS} ${FLAGS} -c $< -o $@

run: compile
	./${LOGIN}

