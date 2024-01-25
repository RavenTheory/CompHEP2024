wget http://www.hepforge.org/archive/pythia6/pythia-6.4.28.f.gz --no-check-certificate

gfortran pythia-6.4.28.f -c -O4
ar -r libpythia-6.4.28.a *.o

gfortran main63.f -o Z0lep.exe -L. -lpythia-6.4.28
gfortran main63b.f -o Z0lep.exe -L. -lpythia-6.4.28
