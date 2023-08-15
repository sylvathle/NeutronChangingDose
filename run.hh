#ifndef RUN_HH
#define RUN_HH

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "G4AnalysisManager.hh"
#include "G4UIcommand.hh"

//#include "functions.hh"
#include "construction.hh"

#include "TMath.h"

#include <vector>
#include <map>

class MyRunAction : public G4UserRunAction
{
	public :
		MyRunAction();
		~MyRunAction();
		
		virtual void BeginOfRunAction(const G4Run*);
		virtual void EndOfRunAction(const G4Run*);
		//G4Run *GenerateRun();
		
		//G4int getNBins() {return NBins;}
		//G4double getMinBin() {return minBin;}
		//G4double getMaxBin() {return maxBin;}

	private:
		G4String rootFileName;
		//std::vector<TString> listParticlesNames;
		
		
		int NBins,Nparts;
		G4double minBin, maxBin;
		std::vector<G4double> bins;
		
		
};

#endif
