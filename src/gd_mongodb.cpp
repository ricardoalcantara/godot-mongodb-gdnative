#include <iostream>

#include <mongocxx/instance.hpp>

#include "gd_mongodb.h"

using namespace godot;

void GDMongoDB::_register_methods() {
	register_method("get_connection", &GDMongoDB::GetConnection);
}

void GDMongoDB::_init() {}

GDMongoDB::GDMongoDB() {}

GDMongoDBConnection GDMongoDB::GetConnection(String uri)
{
    return GDMongoDBConnection(uri);
}