#include "gd_mongodb.h"

using namespace godot;

void GDMongoDBDatabase::_register_methods() {
	register_method("get_collection", &GDMongoDBDatabase::GetCollection);
}

void GDMongoDBDatabase::_init() {}
GDMongoDBDatabase::GDMongoDBDatabase() {}

void GDMongoDBDatabase::Initialize(mongocxx::database database)
{
	_database = database;
}

Ref<GDMongoDBCollection> GDMongoDBDatabase::GetCollection(String collection_name)
{
	mongocxx::collection collection = _database.collection(collection_name.alloc_c_string());
	Ref<GDMongoDBCollection> ref = Ref<GDMongoDBCollection>::__internal_constructor(GDMongoDBCollection::_new()); //hack to prevent leak
	//Ref<GDMongoDBCollection> ret = Ref<GDMongoDBCollection>(GDMongoDBCollection::_new()); <-- should work but leaks
	ref->Initialize(collection);
    return ref;
}
