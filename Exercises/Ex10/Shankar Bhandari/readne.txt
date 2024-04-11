INSTRUCTIONS ON HOW TO DO/ WHAT I DID:

We start with the assumption that GEANT4 is installed and it's parth is in $G4INSTALL.
We also assume DAWN is installed.
(Ok this explanation file probably could've been a pdf, but due to time constraint this .txt is being used).
The resulting pictures from simulation are included as .pdf file with appropriate names.
Now we go to the explanation on how this was done.

First we install the example with following comand:
cmake -DGeant4_DIR=${G4INSTALL}/lib/Geant4-11.1.1 $G4INSTALL/share/Geant4/examples/basic/B2/B2a
make

Then we can run it with:
./exampleB4a

Before running the ./exampleB4a we modify the vs.mac file's line 6 to go from "/vis/open" to "/vis/open DAWNFILE".

When initializing there is a secction (as Appendix 1 in this file below) printed in the terminal.
It says that the detector is a calorimeter with 10 layers of lead and argon, where lead (Pb) is used as a absorber and 
argon as a detecting material.

As per the documentation (https://geant4-userdoc.web.cern.ch/Doxygen/examples_doc/html/ExampleB4.html) the geometry is rectangular
with the structure as shown in figure 1:

#--------------------------------------------------------------------------------------------------------------------------

        |<----layer 0---------->|<----layer 1---------->|<----layer 2---------->|
        |                       |                       |                       |
        ==========================================================================
        ||              |       ||              |       ||              |       ||
        ||              |       ||              |       ||              |       ||
 beam   ||   absorber   |  gap  ||   absorber   |  gap  ||   absorber   |  gap  ||
======> ||              |       ||              |       ||              |       ||
        ||              |       ||              |       ||              |       ||
        ==========================================================================
#--------------------------------------------------------------------------------------------------------------------------
        Figure 1: This figure show the geometry for 3 layers (we have 10), the gap is the detection gap.
#--------------------------------------------------------------------------------------------------------------------------


To simulate the different particles with 10 GeV energy we use the following commands (example for electron):
/gun/particle e-
/gun/energy 10 GeV
/run/beamOn 1

These commands are given in the command line interface after ./exampleB4a starts the program.
For proton we replace "/gun/particle e-" with "/gun/particle proton" and for alpha particle with "/gun/particle alpha".

To change the absorber to water we go to the directory $G4INSTALL/share/Geant4/examples/basic/B4/B4a/src and 
edit the DetectorCconstrucction.cc file and change every instance of "G4_Pb" to "G4_WATER". 
And the material info does indeed change as we can see from the print of the program in Appendix 2.








#-------------------------------------------------------------------------------------------------------
APPENDIX 1:
#-------------------------------------------------------------------------------------------------------
***** Table : Nb of materials = 3 *****

 Material:    G4_Pb    density: 11.350 g/cm3   RadL:   5.613 mm   Nucl.Int.Length:  18.248 cm 
                       Imean: 823.000 eV   temperature: 293.15 K  pressure:   1.00 atm

   --->  Element: Pb (Pb)   Z = 82.0   N =   207   A = 207.217 g/mole
         --->  Isotope: Pb204   Z = 82   N = 204   A = 203.97 g/mole   abundance:  1.400 %
         --->  Isotope: Pb206   Z = 82   N = 206   A = 205.97 g/mole   abundance: 24.100 %
         --->  Isotope: Pb207   Z = 82   N = 207   A = 206.98 g/mole   abundance: 22.100 %
         --->  Isotope: Pb208   Z = 82   N = 208   A = 207.98 g/mole   abundance: 52.400 %
          ElmMassFraction: 100.00 %  ElmAbundance 100.00 % 


 Material: liquidArgon    density:  1.390 g/cm3   RadL:  14.064 cm   Nucl.Int.Length:  86.076 cm 
                       Imean: 188.000 eV   temperature: 293.15 K  pressure:   1.00 atm

   --->  Element: Ar (Ar)   Z = 18.0   N =    40   A = 39.948 g/mole
         --->  Isotope:  Ar36   Z = 18   N =  36   A =  35.97 g/mole   abundance:  0.337 %
         --->  Isotope:  Ar38   Z = 18   N =  38   A =  37.96 g/mole   abundance:  0.063 %
         --->  Isotope:  Ar40   Z = 18   N =  40   A =  39.96 g/mole   abundance: 99.600 %
          ElmMassFraction: 100.00 %  ElmAbundance 100.00 % 


 Material: Galactic    density:  0.000 mg/cm3  RadL: 204310098.490 pc   Nucl.Int.Length: 113427284.261 pc 
                       Imean:  19.200 eV   temperature:   2.73 K  pressure:   0.00 atm

   --->  Element: H (H)   Z =  1.0   N =     1   A =  1.008 g/mole
         --->  Isotope:    H1   Z =  1   N =   1   A =   1.01 g/mole   abundance: 99.989 %
         --->  Isotope:    H2   Z =  1   N =   2   A =   2.01 g/mole   abundance:  0.011 %
          ElmMassFraction: 100.00 %  ElmAbundance 100.00 % 



Checking overlaps for volume Calorimeter:0 (G4Box) ... OK! 
Checking overlaps for volume Abso:0 (G4Box) ... OK! 
Checking overlaps for volume Gap:0 (G4Box) ... OK! 

------------------------------------------------------------
---> The calorimeter is 10 layers of: [ 10mm of G4_Pb + 5mm of liquidArgon ] 
------------------------------------------------------------
World is registered to the default region.

#--------------------------------------------------------------------------------------------------------------------







#-------------------------------------------------------------------------------------------------------
APPENDIX 2:
#-------------------------------------------------------------------------------------------------------
***** Table : Nb of materials = 3 *****

 Material: G4_WATER H_2O   density:  1.000 g/cm3   RadL:  36.083 cm   Nucl.Int.Length:  75.375 cm 
                       Imean:  78.000 eV   temperature: 293.15 K  pressure:   1.00 atm

   --->  Element: H (H)   Z =  1.0   N =     1   A =  1.008 g/mole
         --->  Isotope:    H1   Z =  1   N =   1   A =   1.01 g/mole   abundance: 99.989 %
         --->  Isotope:    H2   Z =  1   N =   2   A =   2.01 g/mole   abundance:  0.011 %
          ElmMassFraction:  11.19 %  ElmAbundance  66.67 % 

   --->  Element: O (O)   Z =  8.0   N =    16   A = 15.999 g/mole
         --->  Isotope:   O16   Z =  8   N =  16   A =  15.99 g/mole   abundance: 99.757 %
         --->  Isotope:   O17   Z =  8   N =  17   A =  17.00 g/mole   abundance:  0.038 %
         --->  Isotope:   O18   Z =  8   N =  18   A =  18.00 g/mole   abundance:  0.205 %
          ElmMassFraction:  88.81 %  ElmAbundance  33.33 % 


 Material: liquidArgon    density:  1.390 g/cm3   RadL:  14.064 cm   Nucl.Int.Length:  86.076 cm 
                       Imean: 188.000 eV   temperature: 293.15 K  pressure:   1.00 atm

   --->  Element: Ar (Ar)   Z = 18.0   N =    40   A = 39.948 g/mole
         --->  Isotope:  Ar36   Z = 18   N =  36   A =  35.97 g/mole   abundance:  0.337 %
         --->  Isotope:  Ar38   Z = 18   N =  38   A =  37.96 g/mole   abundance:  0.063 %
         --->  Isotope:  Ar40   Z = 18   N =  40   A =  39.96 g/mole   abundance: 99.600 %
          ElmMassFraction: 100.00 %  ElmAbundance 100.00 % 


 Material: Galactic    density:  0.000 mg/cm3  RadL: 204310098.490 pc   Nucl.Int.Length: 113427284.261 pc 
                       Imean:  19.200 eV   temperature:   2.73 K  pressure:   0.00 atm

   --->  Element: H (H)   Z =  1.0   N =     1   A =  1.008 g/mole
         --->  Isotope:    H1   Z =  1   N =   1   A =   1.01 g/mole   abundance: 99.989 %
         --->  Isotope:    H2   Z =  1   N =   2   A =   2.01 g/mole   abundance:  0.011 %
          ElmMassFraction: 100.00 %  ElmAbundance 100.00 % 



Checking overlaps for volume Calorimeter:0 (G4Box) ... OK! 
Checking overlaps for volume Abso:0 (G4Box) ... OK! 
Checking overlaps for volume Gap:0 (G4Box) ... OK! 

------------------------------------------------------------
---> The calorimeter is 10 layers of: [ 10mm of G4_WATER + 5mm of liquidArgon ] 
------------------------------------------------------------
World is registered to the default region.

#--------------------------------------------------------------------------------------------------------------------


