# Neutron Dose in water ball
Test of energy deposition in a ball of water by neutrons or protons, dependent initial distance of the beam.
The water ball has a 30cm diameter, its center is the center of the mother volume (0,0,0). 
The initial positions are randomly selected between 16cm and 1m from the center of the ball along the z-axis.
The particle type (proton or neutron) is randomly selected for each event.
A root TTree file is created giving the energy deposited for each neutron or proton and the initial distance from the center of the ball. Protons and neutrons data are stored in separate branches.


## Compile the project

```console
mkdir build
cd build
cmake ..
make
```

## Run the simulation

If you want to run it in visual mode (use implicitly *vis.mac*):
```console
./sim
```

If you want the simulation with 10000 initial neutrons:
```console
./sim run.mac
```


A plot can be produced using the file *plot.cc* (should be moved to the build folder).
