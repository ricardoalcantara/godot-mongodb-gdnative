#include <iostream>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

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

PoolStringArray GDMongoDB::hello_world() {
	mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{}};

    bsoncxx::builder::stream::document document{};

    auto collection = conn["testdb"]["testcollection"];
    document << "hello" << "world";

    collection.insert_one(document.view());
    auto cursor = collection.find({});

    PoolStringArray jsons;

    for (auto&& doc : cursor) {
        jsons.push_back(bsoncxx::to_json(doc).c_str());
    }

    return jsons;
}