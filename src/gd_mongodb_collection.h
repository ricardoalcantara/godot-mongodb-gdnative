#ifndef GDMONGODBCOLLECTION_H
#define GDMONGODBCOLLECTION_H

#include <Godot.hpp>
#include <Reference.hpp>
#include <mongocxx/collection.hpp>

namespace godot {

class GDMongoDBCollection : public Reference {
    private:
	mongocxx::collection _collection;

    public:
    static void _register_methods();
    GDMongoDBCollection(mongocxx::collection collection);
    void _init(); // our initializer called by Godot

	void InsertOne(Dictionary doc);
	Dictionary FindOne(Dictionary doc);

};

}

#endif
