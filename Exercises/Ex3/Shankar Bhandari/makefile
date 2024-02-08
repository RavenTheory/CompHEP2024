#This makefile compiles all the c++ files with extension .cpp
#We directly create an executable from the source code files
#No need to link explicitely

SRC = $(wildcard *main.cpp)
measurement = $(wildcard *measurement.cpp)
header = $(wildcard *.h)


all:
	$(MAKE) compile

object: $(SRC) $(measurement)
	g++ -c $(measurement)

library: object
	ar rvs measurement.a measurement.o

compile: library $(header)
	g++ $(SRC) measurement.a
#This creates the executable file named a.out

RM = $(sort $(wildcard *.a *.o *.out))
clean:
	rm -r $(RM)

cleanAll:
	$(MAKE) clean

test:
	echo $(SRC)

