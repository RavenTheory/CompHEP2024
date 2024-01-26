# COMPUTING METHODS IN HEP

## Project work Spring 2024

### Goal: 
Generator level simulation of a chosen physics channel simulating CMS data taking at the LHC Run3.

To be returned by 24.00 on Friday 24.5.2024

Please use your git repository to return your work. Include in your answer a written description how
you proceed and where you argument any non-trivial choice you make.


### Tools:
   * Monte Carlo simulation like Pythia
   * Cross section calculation
   * Program and script writing
   * ROOT for data storage, plotting, fitting

### Example:

The CMS experiment was designed to be able to measure muons with a good precision. Your
task is to study whether the Higgs boson can be detected in the LHC Run 3 with 13.6 TeV
center-of-mass energy with the discovered mass mH = 125 GeV/c2 in the H → μμ decay channel.
The main backgrounds for this channel are the γ∗ /Z (Drell-Yan) and tt̄ production. Assume
that the collected amount of data will be ∼300 fb−1 .

### Questions:

* What is the expected number of events for each dataset?

* What is the trigger efficiency for the signal?

* The number of events passing the selection.

* If the data were real data, you’d have to present your work to the world-wide scientific
community. Reason why the scientific community should believe in your results. Can you
convince yourself? Why/why not? How would you improve your study to make it more
realistic?

### Tasks:
* Create generator-level datasets with events passing the trigger for thr signal and major backgrounds

* Analyze your data.

   * Identify your physics objects

   * Simulate measurement uncertainties by applying 1% Gaussian smearing to their momenta and 2 mrad Gaussian smearing to their angles θ and φ
	
   * Select your physics objects
	
   * Additional selections

* Report the number of events passing the selection.

* Reconstruct the invariant mass of your physics objects. Produce a ROOT histogram of the reconstructed mass with correct
normalization (i.e. that each entry in the histogram corresponds to a correct amount
of cross-section in fb). Plot two invariant mass distributions in the same figure: the
background only, and the sum of the signal and background.

* Fit the signal+background and background only mass histograms with appropriate functions over an appropriate mass range.

* Choose a reasonable mass window and calculate the number of signal and background events.

* Estimate the statistical significance of the signal peak with the naive expression NS /√NB,
where NS and NB are the number of signal and background events, respectively. 





