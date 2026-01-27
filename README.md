### Test makefile

```make
    game:
	    clang main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

    clean:
	    rm -rf game a.out
```

### Using cmake

```cmake
    cmake -B build
    cd build
    cmake --build . --parallel # or make
    # then run binary
```
