#ifndef GDMONGODBCONNECTION_H
#define GDMONGODBCONNECTION_H

#include <Godot.hpp>
#include <Reference.hpp>
#include <mongocxx/client.hpp>
#include "gd_mongodb_database.h"

namespace godot {

class GDMongoDBConnection : public Reference {
    GODOT_CLASS(GDMongoDBConnection, Reference)

private:
	mongocxx::client* _client;

public:
    static void _register_methods();
    void _init(); // our initializer called by Godot
    GDMongoDBConnection();
    ~GDMongoDBConnection();

	void Connect(String uri);

    Ref<GDMongoDBDatabase> GetDatabase(String database_name);
};

}

#endif
