#include "run.hh"

MyRunAction::MyRunAction()
{
	//listParticlesNames = getParticleList();
	//Nparts = listParticlesNames.size();

	auto man = G4AnalysisManager::Instance();
	man->CreateNtuple("neutron","neutron");
	man->CreateNtupleDColumn("dist");
	man->CreateNtupleDColumn("fedep");
	man->FinishNtuple(0);

	man->CreateNtuple("proton","proton");
	man->CreateNtupleDColumn("dist");
	man->CreateNtupleDColumn("fedep");
	man->FinishNtuple(1);

}

MyRunAction::~MyRunAction()
{	
}

//G4Run* MyRunAction::GenerateRun()
//{ 
//} 

void MyRunAction::BeginOfRunAction(const G4Run* run)
{
	auto man = G4AnalysisManager::Instance();

	//G4RunManager* manager = G4RunManager::GetRunManager();
	//const MyDetectorConstruction *detectorConstruction = static_cast<const MyDetectorConstruction*> (manager->GetUserDetectorConstruction());

	//std::stringstream strRunID;
	//strRunID << runID;
	man->SetDefaultFileType("root");

	rootFileName = G4String("edep.root");
	man->OpenFile(rootFileName);
}

void MyRunAction::EndOfRunAction(const G4Run* run)
{
	auto man = G4AnalysisManager::Instance();
	man->Write();
	man->CloseFile();
}

