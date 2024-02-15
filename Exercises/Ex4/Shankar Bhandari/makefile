#This makefile compiles all the c++ files with extension .cpp
#We directly create an executable from the source code files
#No need to link explicitely

SRC = $(wildcard *.cpp)


all:
	$(MAKE) compile

compile:  $(SRC)
	g++ $(SRC)
#This creates the executable file named a.out

RM = $(sort $(wildcard *.a *.o *.out))
clean:
	rm -r $(RM)

cleanAll:
	$(MAKE) clean

test:
	echo $(SRC)

