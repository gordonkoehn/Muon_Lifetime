//start root
root

//run ReadData.C file in root
.x ReadData.C

//start root with having imported a file
root -l Muon.root

//import root file into root
TFile myfile("Munon.root")

//process list given by loaded file
ntuple1->Process("Analyze.C")

//create Analyze files
ntuple1->MakeSelector("Analyze")
