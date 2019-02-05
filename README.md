# Godot GDNative MongoDB Driver

## godot-cpp compilie

### Linux

```bash
scons -j8 platform=linux generate_bindings=yes bits=64
```

## MongoDB

### Linux

#### mongodb-c

Most of it's from the documentation but ENABLE_STATIC=ON makes it static library and CMAKE_POSITION_INDEPENDENT_CODE=TRUE add -fPIC compile flag for CMAKE

```bash
$ tar xf mongo-c-driver-1.13.1.tar.gz 
$ cd mongo-c-driver-1.13.1/
$ mkdir cmake-build
$ cd cmake-build
$ cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF -DENABLE_STATIC=ON -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE ..
$ make -j 12
$ sudo make install
```

#### mongodb-cxx

Most of it's from the documentation but BUILD_SHARED_LIBS makes=OFF it static library and CMAKE_POSITION_INDEPENDENT_CODE=TRUE add -fPIC compile flag for CMAKE

```bash
$ tar xf mongo-cxx-driver-r3.4.0.tar.gz 
$ cd build/
$ cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local -DBUILD_SHARED_LIBS=OFF -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE ..
$ sudo make EP_mnmlstc_core
$ make -j 8
$ sudo make install
```


## Lib compile

### Linux

```bash
scons -j8 platform=linux
```

