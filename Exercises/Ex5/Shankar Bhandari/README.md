The exericises are done in their own appropriately named files (p1.cxx and p2.cxx).
I have included the example histogram that I got from running the programs myself but not the data used to create it.
In program p2.cxx there is option to change what kind of file the histogram is saved in (.pdf or .root or .C) by uncommenting comment with line of code for that. By default histogram is saved in a pdf file.


The data is not included, but one can run following command in terminal (assuming root is installed) to produce it:
root p1.cxx


And to make histogram using the data created from p1.cxx run the second program with following command:
root p2.cxx

