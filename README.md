### example makefile

```make
    all:
	    clang main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

    clean:
	    rm -rf game a.out
```

### Using cmake

```cmake
    cmake -B build
    cd build
    ninja
    ./algo_visualizer
    # then run binary
```

### Notes

- [x] Draw vertical rectangles
- [x] Add color and height variety
