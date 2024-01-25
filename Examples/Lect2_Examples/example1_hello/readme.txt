1) Fortran compiler
make hello # normal fortran compilation

2) F2C and C compiler
# f2c works with F77, not with F90.
2.1) installing f2c
wget https://netlib.org/f2c/src.tgz
tar xfvz src.tgz
cd src
make -f makefile.u

mkdir lib && cd lib
wget https://netlib.org/f2c/libf2c.zip
unzip libf2c.zip
sed -i 's/CFLAGS = -O/CFLAGS = -O -DNON_UNIX_STDIO -fPIC/' ./makefile.u
make -f makefile.u
ln -s libf2c.a libf2c.so

2.2) compilation
make hello2 # f2c creates first a .c file


