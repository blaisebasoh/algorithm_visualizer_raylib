## Simple Algorithm Visualizer using Raylib (C++)

### Build using Make or automate it using CMake.

### Requirements.

- raylib
- cmake v3.0+
- make or ninja

#### Instal raylib using your distributor's packages manager or if on windows, follow [[raylib.com](https://www.raylib.com/)]

### Building on Linux

### Example makefile

```make
    all:
	    clang main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

    clean:
	    rm -rf game a.out
```

### Using cmake

```cmake
    cmake -B build -G Ninja # don't include '-G Ninja' if using make.
    cd build
    ninja
    ./algo_visualizer
    # then run binary
```

### Notes

- [x] Draw vertical rectangles
- [x] Add color and height variety
- [x] Implement Bubble sort
- [ ] Implement Insertion sort
- [ ] Implement Selection sort
