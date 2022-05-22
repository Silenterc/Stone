#CREDIT FOR THE BASE OF THIS MAKEFILE and DOXYFILE GOES TO RADEK HUSEK, 
#https://gitlab.fit.cvut.cz/husekrad/pa2-cvika-2022/blob/master/cv10/semestralka/Makefile
LOGIN = zimaluk1
CXX = g++
BASIC_FLAGS = -std=c++17 -O2 -g -Wall -pedantic  
FLAGS = -fsanitize=address

SOURCES = $(wildcard src/*.cpp src/*/*.cpp)
OBJECTS = $(patsubst src/%.cpp, build/%.o, ${SOURCES}) #(patsubst original, replacement, sources)
DEPS = $(patsubst src/%.cpp, build/%.dep, ${SOURCES})

.PHONY: fast fast-debug all compile run run-debug valgrind clean doc #these are goals, not files
fast: 
	${MAKE} -j12 compile #compilation on 12 threads

fast-debug: 
	${MAKE} -j12 debug
all: compile doc

debug: BASIC_FLAGS += ${FLAGS}
debug: compile
compile: ${LOGIN}

${LOGIN}: ${OBJECTS}   #$@ is the name of the target(login),$^ is the name of all the Objects, gets called at the end
	@mkdir -p build/
	@mkdir -p build/Effects/
	@mkdir -p build/Cards/
	${CXX} ${BASIC_FLAGS} $^ -o $@ -lstdc++fs 

build/%.o: src/%.cpp   #compiles all the files one by one into .o files, happens first. $< is the first dependency(cpp file)
	@mkdir -p build/
	@mkdir -p build/Effects/
	@mkdir -p build/Cards/
	${CXX} ${BASIC_FLAGS} -c $< -o $@ 

run: compile
	./${LOGIN}

run-debug: fast-debug
	./${LOGIN}

valgrind: compile
	@valgrind --leak-check=full ./${LOGIN}
clean: 
	@rm -f ${LOGIN}
	@rm -rf build doc
doc: 
	doxygen Doxyfile
	
	


