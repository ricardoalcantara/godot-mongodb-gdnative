#include <iostream>
#include <Godot.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/types.hpp>
#include "gd_mongodb_collection.h"

using namespace godot;

// Test class
class MongoViewToDictionary
{
	private:
    const bsoncxx::document::view _view;
	public:
    MongoViewToDictionary(const bsoncxx::document::view& view) : _view(view) { }
    Dictionary GetDictionary()
	{
		Dictionary dict = Dictionary();

		for (bsoncxx::document::element ele : _view) {
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
				case bsoncxx::type::k_int32: {
						bsoncxx::types::value ele_val{ele.get_value()};
						int int_value = ele_val.get_int32();
						dict[str_key] = Variant(int_value);
						break;
					}
				default:
					ERR_PRINT("Invalid type");
			}
		}

		return dict;
	}
};

// Test class
class DictionaryToMongoView
{
	private:
    Dictionary _dictionary;
	bsoncxx::builder::basic::document basic_builder;

	public:	
    DictionaryToMongoView(const Dictionary& dictionary) : _dictionary(dictionary) { }
    bsoncxx::document::view BuildView()
	{
		using bsoncxx::builder::basic::kvp;

		basic_builder = bsoncxx::builder::basic::document{};

		Array keys = _dictionary.keys();
		uint8_t size = keys.size();
		for(uint8_t i = 0; i < size; i++)
		{
			String key = keys[i];
			Variant value = _dictionary[key];

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
				case Variant::Type::INT:
				{
					int v = value;
					basic_builder.append(kvp(std_key, bsoncxx::types::b_int32{v} ));
					break;
				}		
				default:
					ERR_PRINT("Invalid type");
			}
		}

		return basic_builder.view();
	}
};

// Public
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
	auto c = DictionaryToMongoView(doc);
	bsoncxx::document::view view = c.BuildView();;
	_collection.insert_one(view);
}

Dictionary GDMongoDBCollection::FindOne(Dictionary doc)
{
	auto c = DictionaryToMongoView(doc);
	
	bsoncxx::document::view view = c.BuildView();;

	bsoncxx::stdx::optional<bsoncxx::document::value> result = _collection.find_one(view);
	if (result)
	{
		bsoncxx::document::view view_result = result.value().view();
		Dictionary dict = MongoViewToDictionary(view_result).GetDictionary();

		return dict;
	}
	
	return Dictionary();
}