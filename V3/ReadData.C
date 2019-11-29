#include "Riostream.h"

//limit data to valid lifetime
Double_t lowerBound = 2.00;
Double_t upperBound = 18.25;

void ReadData(){

   TFile f1("Muon.root", "recreate");

   ifstream in;
   in.open(Form("%s19-11-21-14-12_decay2.txt", ""));

   Double_t decayTime, unixTime;
   Int_t nlines = 0;
   TNtuple ntuple("ntuple1", "Measured Data", "decayTime:unixTime");

   while (1) {
      in >> decayTime >> unixTime;
      if (!in.good()) break;
      if ((decayTime/1000) > lowerBound && (decayTime/1000) < upperBound){
         ntuple.Fill(decayTime/1000, unixTime);
      }
      nlines++;
   }

   printf("Found %d points\n",nlines);

   in.close();
   f1.Write();
}
