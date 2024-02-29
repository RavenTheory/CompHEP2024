CXX = g++
CXXFLAGS = -Wall -fPIC

# ROOT libraries and include directories
ROOTLIBS = $(shell root-config --libs)
ROOTINC = $(shell root-config --cflags)

# Targets
all: p1

p1: p1.cxx
	$(CXX) $(CXXFLAGS) $(ROOTINC) -o p1 p1.cxx $(ROOTLIBS)

clean:
	rm -f p1
