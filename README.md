# motion_planning
A library to solve motion planning problems

Note: This library makes use of C++17 features.

## Instructions
In order to build this library you have to take the following steps:

Create a build directory:
```bash 
mkdir build
```

Cd in the directory:
```bash 
cd build
```

Execute CMake:
```bash 
cmake -Dtest=ON ..
```

Execute make:
```bash
make
```

If everything went well you should be able to run the tests:
```bash
./runPointTest
```