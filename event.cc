#include "event.hh"
#include <csignal>

MyEventAction::MyEventAction()
//MyEventAction::MyEventAction(MyPrimaryGenerator* generator)
{
	fEdep=0.;
	//fPrimaryExp=0.;
	//gen = generator;
}

MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{
	fEdep=0.;
	//fPrimaryExp = gen->GetPrimaryEnergyExp();
	//G4cout <<  " Event begin event action " << G4endl;
}


void MyEventAction::EndOfEventAction(const G4Event* evt)
{
	//G4cout << "Energy depostion: " << fEdep << G4endl;
	//G4cout << "Primary energy: " << evt->GetPrimaryVertex()->GetPrimary()->GetKineticEnergy() << G4endl;

	

	//G4cout << ibin << " " << evt->GetPrimaryVertex()->GetPrimary()->GetParticleDefinition()->GetParticleName() << G4endl;
	//G4cout << myRun->getMinBin() << " " << prim << " " << myRun->getMaxBin() << " " << minE << " " << maxE << G4endl;	
	//G4cout << prim << " " << ibin << G4endl;

	G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	//G4cout << "Primary particle energy: " << pow(10,gen->GetPrimaryEnergyExp())*MeV << G4endl;
	//G4cout << "Deposited: " << fEdep*MeV << "  " << G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID() << G4endl;
	//man->FillNtupleIColumn(1,0,(int)evt->GetEventID());
	//man->FillNtupleDColumn(1,1,prim);
	G4int ntree;
	if (evt->GetPrimaryVertex()->GetPrimary()->GetParticleDefinition()->GetParticleName() == "neutron") {ntree = 0;}
	else {ntree = 1;}
	man->FillNtupleDColumn(ntree,0,evt->GetPrimaryVertex()->GetZ0());
	man->FillNtupleDColumn(ntree,1,fEdep);
	//G4cout << evt->GetPrimaryVertex()->GetZ0() << " " << fEdep << G4endl;
	//fPrimaryExp = gen->GetPrimaryEnergyExp();
	
	//G4cout << "Deposited energy = " << fEdep << G4endl;
	//if (prim<fEdep)
	//{
	//	G4cout << "WARNING: energy deposited superior to incident energy " << prim << std::setprecision(50) << " " << fEdep << std::setprecision(50) << G4endl;
	//	raise(SIGABRT);
	//}
	
	man->AddNtupleRow(ntree);
	//G4cout <<  " Event end event action " << G4endl;
}

