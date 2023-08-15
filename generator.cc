#include "generator.hh"
#include "Randomize.hh"

#include <math.h> 

template<typename T> T* getRandomObject(const std::vector<T*>& objects)
{
    if (objects.empty())
    {
        // Return a default-constructed object or handle the error as desired
        throw std::logic_error("Cannot select a random object from an empty vector");
    }

    // Seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Generate a random index within the range of the vector
    std::uniform_int_distribution<> dist(0, static_cast<int>(objects.size()) - 1);
    int randomIndex = dist(gen);

    // Return the randomly selected object
    return objects[randomIndex];
}

MyPrimaryGenerator::MyPrimaryGenerator()
{
	fParticleGun = new G4ParticleGun(1);
	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();

	std::vector<G4String> listParticlesNames;
	listParticlesNames.push_back("neutron");
	listParticlesNames.push_back("proton");

	for (int i=0;i<listParticlesNames.size();i++)
	{
		G4ParticleDefinition *particle = particleTable->FindParticle(G4String(listParticlesNames[i]));
		listParticles.push_back(particle);
	}

	G4Random::setTheEngine(new CLHEP::RanecuEngine());
	G4long seed = time(NULL);
	G4Random::setTheSeed(seed);
	
	//auto man = G4AnalysisManager::Instance();
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
	delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event* anEvent)
{
	z0 = CLHEP::RandFlat::shoot(-1.0,-.16)*m;

	// Select randomly the particle type according to the list defined in constructor.
	fParticleGun->SetParticleDefinition(getRandomObject(listParticles));	
	fParticleGun->SetParticlePosition(G4ThreeVector(0.0,0.0,z0));
	fParticleGun->SetParticleEnergy(1e4*MeV);
	fParticleGun->SetParticleMomentumDirection(G4ParticleMomentum(0.,0.,1.));
	fParticleGun->GeneratePrimaryVertex(anEvent);
}

