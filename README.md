## Hierarchical State Machine

## Summary
Hierarchical State Machine implementatino in c++.

## Tech/framework used

<b>Built with</b>
- C++11
- [CMake](https://cmake.org/)
- [Catch2](https://github.com/catchorg/Catch2)

## Features
Implementation of HSM in c++.  
Implementation is using linked list as a way of connecting states. Each state contains one parent and may contain many transitions.  
Two scripts are provided with the application: build.sh to build the application and test.sh to run the unit tests.

Catch2 library was used to unit test the application.  
Project contains full doxygen documentaion.

## Installation

Build application
```bash
./build.sh
```

Run tests
```bash
./test.sh
```

## License
MIT © [Przemysław Bielak]()