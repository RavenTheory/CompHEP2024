The code for Problem 1 is in hdecay.py.
hdecay.py calculates the width for different higgs masses and makes a plot using ROOT. 
The output of this file is Hiss_width_as_function_of_mass_hdecay.pdf and Hiss_width_as_function_of_mass_hdecay.ROOT.

This can be run with "pyroot hdecay.py" and it should work as lonng as there is hdecay program inside the directory hdecay with the executable named run that one gets from using the makefile.
When I did the problem 1, I couldn't make the makefile work with commands using python so it is necessary to do so manually if there is no run executable. 
When doing problem 2 I did notice that I can circumvent this by using bash script that gets called by python, but I didn't go back to implement this on problem 1, since I think it is not really necessary.



The code for problem 2 is in FeynHiggs_Hdecay.py, demo.cc and two scripts feynsetup.sh and runFeynHiggs.sh

For this program it is enough to just run the python program FeynHiggs_Hdecay.
NOTE THAT THE BASH SCRIPTS REQUITE PERMISSION TO EXECUTE!

feynsetup.sh is a bash script that build the FeynHiggs program from the tar file for the programm.
And the python program actually calls this script if necessary so user doesn't have to worry about that.
I have only included the tar file with the script to build the programme since the program itself is quite large while the tar file to build it is not.

runFeynHiggs.sh is a bash script that runs the compiling and executing the resulting file. 
This also directs the output of the executable into a txt file called feyndata.txt for our python program to read.

demo.cc is the file using FeynHiggs that gets compiled and run as demo.exe which then prints the results.
This demo.cc is copy of the example file provided along with the FeynHiggs program, with a small modification that allows for calculating the total width of the SM Higgs.

Finally the FeynHiggs_Hdecay.py is the program that combines all of the scripts and programs mentioned above to give us the graphs using ROOT.
This program also needs the hdecay.py since it uses it as a module and then calls its functions.
The output file of this program are HdecayVsFeynHiggs.pdf and HdecayVsFeynHiggs.ROOT.
This program calls the bash script to build the FeynHiggs programme if it isn't built already.
After the FeynHiggs is built/if it's already there then this program calculates the width using FeynHiggs (via bash script that executes the demo.cc) and the width using HDECAY by calling the functions from hdecay.py.
After calculating the widths this program outputs the data in pdf or a rootfile.

This program can be run with "pyroot FeynHiggs_Hdecay.py" (the bash scripts need to have the permission to execute otherwise the program won't work and might cause some other issues)


