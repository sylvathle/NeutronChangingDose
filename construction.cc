#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{
	//DefineMaterials();
}

MyDetectorConstruction::~MyDetectorConstruction()
{
}

//void MyDetectorConstruction::DefineMaterials()
//{

//}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
	G4NistManager *nist = G4NistManager::Instance();

	G4double xWorld = 0.15*m;
	G4double yWorld = 0.15*m;
	G4double zWorld = 1.0*m;

	worldMat = nist->FindOrBuildMaterial("G4_Galactic");
	solidWorld = new G4Box("solidWorld", xWorld, yWorld, zWorld);
	logicWorld = new G4LogicalVolume(solidWorld,worldMat,"logicWorld");
	physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true);

	phantomMat = nist->FindOrBuildMaterial("G4_WATER");
	solidPhantom = new G4Sphere("solidPhantom", 0., 0.15*m, 0, 360*deg, 0, 180*deg);
	logicPhantom = new G4LogicalVolume(solidPhantom, phantomMat, "logicPhantom");
	fScoringVolume = logicPhantom;
	physPhantom = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicPhantom, "physPhantom", logicWorld, false, 0, true);
	
	return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{
	MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
	logicPhantom->SetSensitiveDetector(sensDet);
}





