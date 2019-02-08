#ifndef GDMONGODBDATABASE_H
#define GDMONGODBDATABASE_H

#include <Godot.hpp>
#include <Reference.hpp>
#include <mongocxx/database.hpp>
#include "gd_mongodb_collection.h"

namespace godot {

class GDMongoDBDatabase : public Reference {
    GODOT_CLASS(GDMongoDBDatabase, Reference)

private:
	mongocxx::database _database;
public:
    static void _register_methods();
    void _init(); // our initializer called by Godot
    GDMongoDBDatabase();

	void Initialize(mongocxx::database database);

    Ref<GDMongoDBCollection> GetCollection(String collection_name);
};

}
#endif
