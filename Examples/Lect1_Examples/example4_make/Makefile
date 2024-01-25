SRC = $(wildcard *.cpp)
OBJECTS = $(addsuffix .o $(basename $(SRC)))

all:
	$(MAKE) compile
	$(MAKE) hello
	$(MAKE) run

.cpp.o:
	$(CXX) -c $<

test:
	echo $(SRC)
	echo $(OBJECTS)

compile: hello.o


hello: hello.o
	$(CXX) hello.o -o hello

run:
	@./hello

GARBAGE = $(wildcard *.o *~)
clean:
	rm $(GARBAGE)
