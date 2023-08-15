#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"

#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleMomentum.hh"

//#include "functions.hh"

#include <vector>
#include <random>
#include <iostream>


class MyPrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
	public :
		MyPrimaryGenerator();
		~MyPrimaryGenerator();
		
		virtual void GeneratePrimaries(G4Event*);
		
		//G4double GetPrimaryEnergy() {return this->e0;}
		//G4double GetPrimaryEnergyExp() {return this->exp_e0;}
		G4double getDistance() {return this->z0;}
		
	private :
		G4ParticleGun *fParticleGun;
		//G4double x0, y0, z0, e0;
		G4double z0;
		std::vector<G4ParticleDefinition *> listParticles;
		
};

#endif
