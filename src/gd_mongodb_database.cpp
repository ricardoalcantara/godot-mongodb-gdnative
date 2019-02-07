#include "gd_mongodb.h"

using namespace godot;

void GDMongoDBDatabase::_register_methods() {
	register_method("get_collection", &GDMongoDBDatabase::GetCollection);
}

void GDMongoDBDatabase::_init() {}

GDMongoDBDatabase::GDMongoDBDatabase(mongocxx::database database)
{
	_database = database;
}

GDMongoDBCollection GDMongoDBDatabase::GetCollection(String collection_name)
{
	mongocxx::collection collection = _database.collection(collection_name.alloc_c_string());
    return GDMongoDBCollection(collection);
}
