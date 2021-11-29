# SWEN2 Sorter CLI

This project is a CLI-based sorter which support the bubble sort, merge sort, and heap sort.

## How to build

The Makefile of this project is generated with CMake. To build you own file, install CMake and run the following commands.

```
cd build
```

```
cmake -G "Unix Makefiles" ..
```

```
make
```

## Running the project

To get the project, download a pre-built binary or build it yourself using the steps described above.

## Usage

```
usage: sort [--help] [--verbose]
  <--algorithm <algorithm>> <args>

available algorithms
  bubble
  merge
  heap
```
