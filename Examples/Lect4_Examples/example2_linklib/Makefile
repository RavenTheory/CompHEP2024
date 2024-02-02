OBJS = src/MyLib.o

OPT = -O -Wall -fPIC

INC = -Iinclude

LIBS = -L. -lMyLib

all:
	$(MAKE) libMyLib.so
	$(CXX) example4.2.cpp $(INC) $(LIBS) -o example4.2

libMyLib.so: $(OBJS)
	$(CXX) -shared -O $(OBJS) -o libMyLib.so

.cc.o:
	$(CXX) -c $(OPT) $(INC) $< -o $@



clean:
	rm -f *~ $(OBJS)

cleanAll:
	$(MAKE) clean
	rm -f example4.2 libMyLib.so
