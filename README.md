# Panoramix - Concurrent Programming Project

## Overview
Panoramix simulates a scenario where villagers consume potions and engage in fights, requiring synchronization using threads and mutexes in C.

## Project Requirements
- **Language**: C
- **Compilation**: Makefile with `make`, `make re` (rebuild), `make clean` (remove object files), `make fclean` (remove object files and executable).
- **Error Handling**: Errors output to stderr, exiting with error code 84 for errors, 0 for success.

## Usage
```bash
./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>
```
- `nb_villagers`: Number of villagers (> 0).
- `pot_size`: Maximum potion capacity (> 0).
- `nb_fights`: Maximum fights each villager will engage in (> 0).
- `nb_refills`: Maximum number of times the druid refills the pot (> 0).

## Program Rules
1. Villagers consume potions and fight Romans.
2. When the pot is empty, villagers wake up the druid for a refill.
3. Threads and mutexes are used for synchronization.

## Directory Structure
- `bonus/`: Directory containing bonus files, including potential specific Makefile.

## Files
- `panoramix.c`: Main program file.
- Other source files (excluding binaries, temporary files, and object files).

## Compilation
To compile:
```bash
make
```
To clean object files:
```bash
make clean
```
To clean object files and executable:
```bash
make fclean
```

## Error Codes
- `0`: Successful execution.
- `84`: Error during execution (e.g., invalid input parameters).

## Example
```bash
./panoramix 5 10 3 2
```
This command starts the simulation with 5 villagers, a pot size of 10, each villager can engage in up to 3 fights, and the druid will refill the pot up to 2 times.
