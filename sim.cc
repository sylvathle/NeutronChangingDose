#include <iostream>

#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

//#include "QBBC_HP.hh"
#include "QBBC.hh"
#include "QGSP_BERT.hh"

#include "construction.hh"
#include "physics.hh"
#include "action.hh"

//#include "plotcatalog.hh"
//#include "shieldmaterial.hh"

int main(int argc, char** argv)
{
	time_t start,end;

	time(&start);

	#ifndef G4MULTITHREADED
		G4MTRunManager *runManager = new G4MTRunManager();
	#else
		G4RunManager *runManager = new G4RunManager();
	#endif

	//G4String *shieldmaterial= new G4String("G4_Galactic");
	//G4String *shieldmaterialname= new G4String("G4_Al");
	//ShieldMaterial* shieldmaterial = new ShieldMaterial(shieldmaterialname);

	std::cout << "Before construction" << std::endl;
	runManager->SetUserInitialization(new MyDetectorConstruction());
	std::cout << "After construction" << std::endl;
	//runManager->SetUserInitialization(new MyPhysicsList());
	runManager->SetUserInitialization(new QBBC());
	runManager->SetUserInitialization(new MyActionInitialization());

	//G4VModularPhysicsList* physics = new QGSP_BERT();
	//G4VModularPhysicsList* physics = new QBBC();
    	//physics->RegisterPhysics(new G4HadronPhysicsQGSP_BIC_HP());
	//runManager->SetUserInitialization(physics);
	
	G4UImanager *UImanager = G4UImanager::GetUIpointer();
	
	if (argc==1)
	{
		G4UIExecutive *ui;
		ui = new G4UIExecutive(argc,argv);
	
		G4VisManager *visManager = new G4VisExecutive();
		visManager->Initialize();
                G4cout << "After init visManagher" << G4endl;
		UImanager->ApplyCommand("/control/execute vis.mac");
                G4cout << "Command applied" << G4endl;
		ui->SessionStart();
                G4cout << "Session started" << G4endl;
	}
	else
	{
		G4String command = "/control/execute ";
		G4String fileName = argv[1];
		UImanager->ApplyCommand(command+fileName);
	}

	time(&end);

	

	double time_taken = double(end-start);
	G4cout << "Execution time: " << time_taken << std::setprecision(5) << "sec" << G4endl;

	return 0;
}
