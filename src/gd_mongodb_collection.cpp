#include <iostream>

#include "gd_mongodb_collection.h"

using namespace godot;

void GDMongoDBCollection::_register_methods() {
	register_method("insert_one", &GDMongoDBCollection::InsertOne);
	register_method("find_one", &GDMongoDBCollection::FindOne);
}

void GDMongoDBCollection::_init() {}

GDMongoDBCollection::GDMongoDBCollection(mongocxx::collection collection)
{
	_collection = collection;
}

void GDMongoDBCollection::InsertOne(Dictionary doc)
{
	// _collection.insert_one(doc->Extract());
}

Dictionary GDMongoDBCollection::FindOne(Dictionary doc)
{
    Dictionary dict = Dictionary();
    dict["Name"] = Variant("Ricardo");
    dict["Age"] = Variant(31);
    dict["size"] = Variant(1.76f);

    return dict;
	// bsoncxx::stdx::optional<bsoncxx::document::value> result = _collection.find_one(doc->Extract());
	// if (result)
	// {
	// 	bsoncxx::document::value value = result.value();
	// 	return new GDDocumentView(value);
	// }
	// else
	// {
	// 	return NULL;
	// }
}