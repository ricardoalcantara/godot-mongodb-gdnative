# Godot GDNative MongoDB Driver

This is not even close to usable.

This is an interface to access MongoDB using mongo-cxx official lib.

It's already connect but not more than that.

## godot-cpp compilie

### Linux

```bash
scons -j8 platform=linux generate_bindings=yes bits=64
```

## MongoDB

### Windows

#### mongodb-c

```bash
cmake -G "Visual Studio 15 2017 Win64" "-DCMAKE_INSTALL_PREFIX=D:\mongo_driver\mongo_c_driver" "-DENABLE_SSL=WINDOWS" "-DCMAKE_PREFIX_PATH=D:\mongo_driver\mongo_c_driver" "-DENABLE_STATIC=ON" "-DENABLE_EXTRA_ALIGNMENT=OFF" ..

msbuild.exe /p:Configuration=RelWithDebInfo ALL_BUILD.vcxproj

msbuild.exe INSTALL.vcxproj
```

#### mongodb-cxx

```bash
cmake -G "Visual Studio 15 2017 Win64" "-DCMAKE_INSTALL_PREFIX=D:\mongo_driver\mongo_cxx_driver" "-DBSONCXX_POLY_USE_BOOST=1" "-DCMAKE_PREFIX_PATH=D:\mongo_driver\mongo_c_driver" "-DBUILD_SHARED_LIBS=OFF" "-DBOOST_ROOT=D:\mongo_driver\boost_1_69_0" ..

msbuild.exe ALL_BUILD.vcxproj

msbuild.exe INSTALL.vcxproj

```

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

