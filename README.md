# Neutron Dose in water ball
Test of energy deposition in a ball of water (30cm in diameter) by neutrons, dependency initial distance of the beam (randomly selected between 16cm and 1m from the center of the ball).

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

A root file is created giving the energy deposited per neutron and the initial distance from the center of the ball.
A plot can be produced using the file *plot.cc* (should be moved to the build folder).
