#include <mongocxx/uri.hpp>
#include <mongocxx/client.hpp>
#include <assert.h>
#include "gd_mongodb_connection.h"

using namespace godot;

void GDMongoDBConnection::_register_methods() {
	register_method("get_database", &GDMongoDBConnection::GetDatabase);
}

void GDMongoDBConnection::_init() {}
GDMongoDBConnection::GDMongoDBConnection() {}

void GDMongoDBConnection::Connect(String uri)
{
	mongocxx::uri _uri{uri.alloc_c_string()};
	// mongocxx::client client{mongocxx::uri{}};
	_client = new mongocxx::client{mongocxx::uri{}};
}

GDMongoDBConnection::~GDMongoDBConnection()
{
	delete _client;
}

Ref<GDMongoDBDatabase> GDMongoDBConnection::GetDatabase(String database_name)
{
	assert(_client);

	mongocxx::database database = _client->database(database_name.alloc_c_string());
	Ref<GDMongoDBDatabase> ref = Ref<GDMongoDBDatabase>::__internal_constructor(GDMongoDBDatabase::_new()); //hack to prevent leak
	//Ref<GDMongoDBDatabase> ret = Ref<GDMongoDBDatabase>(GDMongoDBDatabase::_new()); <-- should work but leaks
	ref->Initialize(database);
    return ref;
}