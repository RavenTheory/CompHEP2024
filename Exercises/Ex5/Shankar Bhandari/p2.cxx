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
    
    myCanvas -> Print("Histogram.pdf")
    //myCanvas -> Print("Histogram.root");
    //myCanvas -> Print("Histogram.C");

}