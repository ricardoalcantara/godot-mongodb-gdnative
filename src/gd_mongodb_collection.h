#ifndef GDMONGODBCOLLECTION_H
#define GDMONGODBCOLLECTION_H

#include <Godot.hpp>
#include <Reference.hpp>
#include <mongocxx/collection.hpp>
#include <bsoncxx/builder/stream/document.hpp>

namespace godot {

class GDMongoDBCollection : public Reference {
	GODOT_CLASS(GDMongoDBCollection, Reference)

    private:
	mongocxx::collection _collection;

    public:
    static void _register_methods();
    void _init(); // our initializer called by Godot
    GDMongoDBCollection();

	void Initialize(mongocxx::collection collection);
	void InsertOne(Dictionary doc);
	Dictionary FindOne(Dictionary doc);
};

}

#endif
