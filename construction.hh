#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4Box.hh"
#include "G4Sphere.hh"

#include "G4NistManager.hh"

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "G4SystemOfUnits.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4VPrimitiveScorer.hh"

#include "detector.hh"
#include "G4SDManager.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
	public:
		MyDetectorConstruction();
		~MyDetectorConstruction();
		
		G4LogicalVolume *GetScoringVolume() const { return fScoringVolume; }
		
		virtual G4VPhysicalVolume *Construct();
	
	private:
		G4Material *worldMat, *phantomMat;
	
		G4Sphere *solidPhantom;
		G4Box *solidWorld;
		G4LogicalVolume *logicWorld, *logicPhantom, *fScoringVolume;
		G4VPhysicalVolume *physWorld, *physPhantom;
		
		//void DefineMaterials();
		virtual void ConstructSDandField();
};

#endif
