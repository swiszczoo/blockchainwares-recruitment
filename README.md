# BlockChainWares recruitment task

## Building and running

First, install dependencies of `fc` library. On Ubuntu 20.04, run (assuming you use `apt` package manager):
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

Then create a new directory and run CMake by entering the following commands:

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