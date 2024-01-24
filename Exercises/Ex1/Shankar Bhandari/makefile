SRC = $(basename $(wildcard *.tex))

all:
	$(MAKE) -i tex
	$(MAKE) mf
	$(MAKE) biber
	$(MAKE) tex
	$(MAKE) dvips
	$(MAKE) pdf

tex:
	latex $(SRC)

mf:
	mf "\mode=localfont; input fd.mf;"
	
biber:
	biber $(SRC)

dvips:
	dvips $(SRC) -o
	
pdf:
	ps2pdf $(SRC).ps

RM = $(sort $(wildcard *.dvi *.log *.aux fd* *~))
clean:
	rm -r $(RM)

cleanAll:
	$(MAKE) clean
	rm -rf *.ps

test:
	echo $(SRC)

