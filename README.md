# game-of-life-simulator
Game of Life Simulator with variable board size and evolutions to map survival percentages


### Objective
The goal is to map variables, namely board size to survability via running simulations of games and testing to see whether or not anyone is alive after an input number of evolutions. A given number of simulations can be performed with the survivability recorded and after the survability percentage calculated after the simulation.

### Variables
- randomness for initial positioning is performed by rand() function seeded with time (50/50 chance, no favoritism)
- board size x
- board size y
- number of evolutions per simulation
- number of simulations to perform before calculating board survival percentage
- open vs closed borders (really just a smaller board if closed borders)

### Non-intentionally adjustable variables
- survivability per evolution parameters (if you look closely)

### Future updates
- rewrite most of the pieces in classes for code clarity
- create a randomness variable for board initalization (i.e. mean: 40% coverage, std. dev. 5%)
- create a gui for better visualization
