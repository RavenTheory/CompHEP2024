SRC = $(wildcard *.f)
CSRC = $(addsuffix .c,$(basename $(SRC)))

INC = -Isrc
LIBS = -Llib -lf2c -lm

.f.c:
	src/f2c $(SRC)

all: 
	$(MAKE) hello

hello2: $(CSRC)
	$(CC) $(CSRC) $(INC) $(LIBS) -o hello2

hello:
	$(FC) $(SRC) -o hello

clean:
	rm -f $(CSRC)
	rm -f *~

cleanAll:
	$(MAKE) clean
	rm -f hello hello2
	rm -rf src.tgz src lib
