PYTHIA8_URL = https://pythia.org/download/pythia83/pythia8311.tgz
PYTHIA8_TGZ = $(notdir $(PYTHIA8_URL))
PYTHIA8_DIR = $(basename $(PYTHIA8_TGZ))

OPT = -g -Wall
INC = -I$(PYTHIA8_DIR)/include
LIBS = -L$(PYTHIA8_DIR)/lib -lpythia8 -ldl


$(PYTHIA8_DIR):
	wget $(PYTHIA8_URL)
	tar xfvz $(PYTHIA8_TGZ)
	cd $(PYTHIA8_DIR) && ./configure && make

all: 
	$(MAKE) $(PYTHIA8_DIR)

%:
	cp $(PYTHIA8_DIR)/examples/$@.cc .
	$(CXX) $(OPT) $(INC) $@.cc $(LIBS) -o $@

files = $(wildcard *~ main* pythia* *.exe *.txt)
clean:
	rm -rf $(files)

cleanAll:
	$(MAKE) clean

both:
	$(MAKE) p1
	$(MAKE) simulateEvents

p1:
	$(CXX) $(OPT) $(INC) $@.cc $(LIBS) -o p1.exe

simulateEvents:
	$(CXX) $(OPT) $(INC) $@.cc $(LIBS) -o simulation.exe




