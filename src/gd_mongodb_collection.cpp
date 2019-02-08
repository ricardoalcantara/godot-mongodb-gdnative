#include <iostream>
#include <Godot.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/types.hpp>
// #include <bsoncxx/json.hpp>
#include <bsoncxx/types.hpp>
#include "gd_mongodb_collection.h"

using namespace godot;

void GDMongoDBCollection::_register_methods() {
	register_method("insert_one", &GDMongoDBCollection::InsertOne);
	register_method("find_one", &GDMongoDBCollection::FindOne);
}

void GDMongoDBCollection::_init() {}
GDMongoDBCollection::GDMongoDBCollection() {}

void GDMongoDBCollection::Initialize(mongocxx::collection collection)
{
	_collection = collection;
}

void GDMongoDBCollection::InsertOne(Dictionary doc)
{
	using bsoncxx::builder::basic::document;
	using bsoncxx::builder::basic::kvp;
	
	document basic_builder{};

	Array keys = doc.keys();
	uint8_t size = keys.size();
	for(uint8_t i = 0; i < size; i++)
	{
		String key = keys[i];
		Variant value = doc[key];

		std::string std_key = key.alloc_c_string();

		switch (value.get_type())
		{
			case Variant::Type::STRING:
			{
				String v = value;
				std::string std_value = v.alloc_c_string();
				basic_builder.append(kvp(std_key, std_value ));
				break;
			}		
			default:
				ERR_PRINT("Invalid type");
		}
	}
	
	_collection.insert_one(basic_builder.view());
}

Dictionary GDMongoDBCollection::FindOne(Dictionary doc)
{
	// using bsoncxx::builder::basic::document;
	
    Dictionary dict = Dictionary();
    // dict["Name"] = Variant("Ricardo");
    // dict["Age"] = Variant(31);
    // dict["size"] = Variant(1.76f);

    // return dict;
	bsoncxx::stdx::optional<bsoncxx::document::value> result = _collection.find_one({});
	
	bsoncxx::document::view view = result.value().view();

	for (bsoncxx::document::element ele : view) {
		std::string field_key{ele.key()};
		String str_key = field_key.c_str();

		switch (ele.type()) {
			case bsoncxx::type::k_oid: {
					bsoncxx::types::value ele_val{ele.get_value()};

					std::string str_value = ele_val.get_oid().value.to_string();

					dict[str_key] = Variant(str_value.c_str());
					break;
				}
			case bsoncxx::type::k_utf8: {
					bsoncxx::types::value ele_val{ele.get_value()};

					std::string str_value = ele_val.get_utf8().value.to_string();

					dict[str_key] = Variant(str_value.c_str());
					break;
				}
			default:
				ERR_PRINT("Invalid type");
		}
	}

	return dict;
}