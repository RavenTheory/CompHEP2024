#include <iostream>
#include "TFile.h"
#include "TRandom3.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TH1D.h"
//using namespace std;

//THIS PROGRAM COMBINES THE p1 and p2 FROM THE EXERCISE 5 SINCE IT NEEDS TO BE COMPILED AND NEEDS A MAIN FUNCTION


// this is the function from p1:
void p1(){

    TFile* outputFile = new TFile("random_numbers.root", "RECREATE");
    TTree nums("nums", "Tree to store randomly generated number that are normally distributed");



    double randomnum;

    nums.Branch("randomnum", &randomnum, "randomnum/D");

    TRandom3 randgenerator;

    int N = 1000;
    for (int i =0 ; i<N; ++i ){
        randomnum = randgenerator.Gaus(0, 1); 
        // has mean of 0 and sigma of 1
        nums.Fill();
    }

    nums.Write();

    outputFile -> Close();


    std::cout << N << " normally distributed random numbers have been generated and saved into a root file called random_numbers.root." << std::endl ; 

}


// this is the function from p2:
void p2(){

    TFile* inputFile = new TFile("random_numbers.root", "READ");


    TTree* nums = (TTree*)gFile -> Get("nums");
    double randomnum;
    nums -> SetBranchAddress("randomnum", &randomnum);


    TCanvas* myCanvas = new TCanvas("myCanvas", "", 800, 600);
    myCanvas -> SetFillColor(0);

    TH1D* histo = new TH1D("Histogram", "Randomly generated numbers",  20, -5, 5);


    int entries = nums -> GetEntries();
    for (int i=0; i< entries; i++){
        nums -> GetEntry(i); 
        histo->Fill(randomnum);
        //cout << randomnum << "debug" << endl;
    }

    histo -> GetXaxis() -> SetTitle("x-axis");
    histo -> GetYaxis() -> SetTitle("y-axis");
    


    histo -> SetLineColor(kBlack);
    histo -> SetLineWidth(4);
    histo -> SetFillColor(kYellow);

    histo -> Fit("gaus");


    //histo -> Scale(1);
    //For some reason this kinda breaks the histogram
    histo -> Draw();

    //Choose which form you want to print(save) the canvas:

    //pdf or root file or .C file:
    
    myCanvas -> Print("Histogram.pdf");
    //myCanvas -> Print("Histogram.root");
    //myCanvas -> Print("Histogram.C");


    //Let's close the file
    inputFile -> Close();
}


// the main function calls the functions p1 and p2:
int main(){

    p1();
    p2();

    return 0;
}














