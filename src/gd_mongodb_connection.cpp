#include <mongocxx/uri.hpp>
#include <mongocxx/client.hpp>
#include "gd_mongodb_connection.h"

using namespace godot;

void GDMongoDBConnection::_register_methods() {
	// register_method("get_database", &GDMongoDBConnection::GetDatabase);
}

void GDMongoDBConnection::_init() {}

GDMongoDBConnection::GDMongoDBConnection(String uri)
{
	mongocxx::uri _uri{uri.alloc_c_string()};
	_client = new mongocxx::client{_uri};
}

GDMongoDBConnection::~GDMongoDBConnection()
{
	delete _client;
}

GDMongoDBDatabase GDMongoDBConnection::GetDatabase(String database_name)
{
	mongocxx::database database = _client->database(database_name.alloc_c_string());
    return GDMongoDBDatabase(database);
}