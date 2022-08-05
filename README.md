# BlockChainWares recruitment task

## About

The solution of the task is split into two separate namespaces:

+ `abstract`, which contains expressions that support a well-known Visitor pattern, based on abstractions, virtual functions and runtime polymorphism
+ `static_v`, which contains implementations of expressions that can be put into `fc::static_variant` type and visited using a modern Static Visitor pattern

Expression classes differ slighly in implementation. For example `add` and `mul` classes accept an `std::initializer_list` in their constructors and hold an `std::vector` internally, while e.g. `div` class accepts exactly two parameters in constructor and contains a pair of `int`s. Hence, expression classes are not interchangeable and using a Visitor pattern is more relevant.

Expression implementations in `abstract_expressions.cpp` and `static_expressions.cpp` are very similar, however there are no `accept` methods in `static_v` namespace because they are not required for the Static Visitor to work.

In addition, the project contains a couple of simple unit tests, as well as a basic CI/CD script - to ensure that it compiles and runs on Ubuntu 20.04.

## Build and run

The project can be built using CMake 3.2+.

First, clone this repository recursively (`googletest` is included as a git submodule) by running the following command:
```
git clone --recurse-submodules https://github.com/swiszczoo/blockchainwares-recruitment.git
```

Then install dependencies of `fc` library. On Ubuntu 20.04, run (assuming you use `apt` package manager):
```
sudo apt-get install \
libboost-thread-dev \
libboost-date-time-dev \
libboost-system-dev \
libboost-filesystem-dev \
libboost-program-options-dev \
libboost-serialization-dev \
libboost-chrono-dev \
libboost-test-dev \
libboost-context-dev \
libboost-locale-dev \
libboost-iostreams-dev \
libboost-coroutine-dev \
libncurses-dev \
libreadline-dev \
zlib1g-dev \
libbz2-dev
```

Afterwards, create a new directory called `build` and run CMake there by entering the following commands:

```
mkdir build
cd build
cmake ..
```

Then simply build the project by running:
```
cmake --build .
```

CMake should create a new executable in the `build/` directory, called `expressions`. Run it by executing:
```
./expressions
```

If you didn't explicitly pass any additional options to CMake, an additional executable containing a few simple unit tests should have been built. You can run it from the `build/` directory using the following command:
```
./expressions_tests
```