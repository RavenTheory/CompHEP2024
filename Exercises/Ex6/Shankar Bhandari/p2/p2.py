import ROOT
import ctypes

def create_histogram():
    # Open the ROOT file
    input_file = ROOT.TFile("random_numbers.root", "READ")

    # Get the TTree from the file
    nums = input_file.Get("nums")
    randomnum = ctypes.c_double(0.0)  # Create a ctypes double
    nums.SetBranchAddress("randomnum", randomnum)

    # Create a canvas
    my_canvas = ROOT.TCanvas("myCanvas", "", 800, 600)
    my_canvas.SetFillColor(0)

    # Create a histogram
    histo = ROOT.TH1D("Histogram", "Randomly generated numbers", 20, -5, 5)

    # Fill the histogram
    entries = nums.GetEntries()
    for i in range(entries):
        nums.GetEntry(i)
        histo.Fill(randomnum.value)  # Access the value from ctypes

    # Set axis titles
    histo.GetXaxis().SetTitle("x-axis")
    histo.GetYaxis().SetTitle("y-axis")

    # Set histogram properties
    histo.SetLineColor(ROOT.kBlack)
    histo.SetLineWidth(4)
    histo.SetFillColor(ROOT.kYellow)

    # Fit the histogram
    histo.Fit("gaus")

    # Draw the histogram
    histo.Draw()

    # Save the canvas as a PDF
    my_canvas.Print("Histogram.pdf")
    # Alternatively, save as a root file or .C file:
    # my_canvas.Print("Histogram.root")
    # my_canvas.Print("Histogram.C")
    input("Press enter to exit")

if __name__ == "__main__":
    create_histogram()
