#include <mongocxx/instance.hpp>

#include "gd_mongodb.h"

using namespace godot;

mongocxx::instance* GDMongoDB::mongocxx_instance = 0;

void GDMongoDB::_register_methods() {
	register_method("initialize", &GDMongoDB::Initialize);
	register_method("get_connection", &GDMongoDB::GetConnection);
}

void GDMongoDB::_init()
{
	if (GDMongoDB::mongocxx_instance == 0)
    {
        GDMongoDB::mongocxx_instance = new mongocxx::instance();
    }
}

GDMongoDB::GDMongoDB() {}

void GDMongoDB::Initialize()
{
}

Ref<GDMongoDBConnection> GDMongoDB::GetConnection(String uri)
{
	Ref<GDMongoDBConnection> ref = Ref<GDMongoDBConnection>::__internal_constructor(GDMongoDBConnection::_new()); //hack to prevent leak
	//Ref<GDMongoDBConnection> ref = Ref<GDMongoDBConnection>(GDMongoDBConnection::_new()); // <-- should work but leaks
	ref->Connect(uri);
    return ref;
}