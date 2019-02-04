#include "gd_mongodb.h"

using namespace godot;

void GDMongoDB::_register_methods() {
	register_method("hello_world", &GDMongoDB::hello_world);
}

GDMongoDB::GDMongoDB() {
}

GDMongoDB::~GDMongoDB() {
    // add your cleanup here
}

void GDMongoDB::_init() {
}

String GDMongoDB::hello_world() {
	return "Hello World";
}