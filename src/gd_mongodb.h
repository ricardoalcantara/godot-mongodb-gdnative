#ifndef GDMONGODB_H
#define GDMONGODB_H

#include <Godot.hpp>
#include <Reference.hpp>
#include <mongocxx/instance.hpp>
#include "gd_mongodb_connection.h"

namespace godot {

class GDMongoDB : public Reference {
    GODOT_CLASS(GDMongoDB, Reference)

private:
    static mongocxx::instance* mongocxx_instance;

public:
    static void _register_methods();
    void _init(); // our initializer called by Godot
    GDMongoDB();

	void Initialize();

    Ref<GDMongoDBConnection> GetConnection(String uri);
};

}

#endif