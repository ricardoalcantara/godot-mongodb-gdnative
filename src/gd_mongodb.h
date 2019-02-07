#ifndef GDMONGODB_H
#define GDMONGODB_H

#include <Godot.hpp>
#include <Reference.hpp>

namespace godot {

class GDMongoDB : public Reference {
    GODOT_CLASS(GDMongoDB, Reference)

private:
    float time_passed;

public:
    static void _register_methods();

    GDMongoDB();
    ~GDMongoDB();

    void _init(); // our initializer called by Godot

    PoolStringArray hello_world();
    Dictionary get_dict();
};

}

#endif