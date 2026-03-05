## Simple Algorithm Visualizer using Raylib (C++)

## Prerequisites
- **Compiler**: GCC or Clang
- **Build System**: CMake 3.11+, Ninja/Make
- **Dependencies**: vcpkg

## Build Instructions

### Windows (MinGW)

Ensure `VCPKG_ROOT` is set in your environment variables.
I use vcpkg for all C/C++ libraries I use.


**Install Dependencies**:
```ps
# install raylib using vcpkg
vcpkg install raylib:x64-mingw-dynamic

# configure and build
cmake --preset mingw-debug
cmake --build build
```
**Linux**
```bash
cmake -B build -G Ninja
cmake --build build
./build/algo_visualizer
```
Development Environment (LSP)

**### Todo**
- [x] Primitive rendering (Rectangles)
- [x] Dynamic height scaling/color mapping
- [x] Bubble Sort (Synchronous animation)
- [ ] Insertion Sort
- [ ] Selection Sort
- [ ] Quick Sort
