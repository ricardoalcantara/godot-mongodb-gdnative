# Godot GDNative MongoDB Driver

## godot-cpp compilie

### Linux

```bash
scons -j8 platform=linux generate_bindings=yes bits=64
```

## Lib compile

### Linux

```bash
scons -j8 platform=linux
```

## MongoDB

```bash
# gcc -D defines a macro to be used by the preprocessor.
-DMONGOCXX_STATIC -DBSONCXX_STATIC -DMONGOC_STATIC -DBSON_STATIC \

# gcc -I adds include directory of header files.
-I/usr/local/include/libmongoc-1.0 \
-I/usr/local/include/libbson-1.0 \
-I/usr/local/include/mongocxx/v_noabi \
-I/usr/local/include/bsoncxx/v_noabi \

# gcc -L looks in directory for library files.
-L/usr/local/lib \

# gcc -l links with a library file.
 -lmongocxx-static -lbsoncxx-static -lmongoc-static-1.0 -lsasl2 -lssl -lcrypto -lbson-static-1.0 -lm -lpthread
```