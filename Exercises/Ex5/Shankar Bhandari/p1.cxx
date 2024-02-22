
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


    cout << N << " normally distributed random numbers have been generated and saved into a root file called random_numbers.root." << endl;



}