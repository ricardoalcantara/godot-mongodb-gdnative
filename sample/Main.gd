extends Node

# Declare member variables here. Examples:
# var a = 2
# var b = "text"

# Called when the node enters the scene tree for the first time.
func _init():
#	instantiating a GDNative class
	var mongodb = load("res://bin/gdmongodb.gdns").new()
	var conn = mongodb.get_connection("mongodb://127.0.0.1:27017")
	var db = conn.get_database("testdb")
	var coll = db.get_collection("testcollection")
	var n_doc = { "Name": "Ricardo", "Age": 31 }
	coll.insert_one(n_doc)
	var doc = coll.find_one({"Age": 31})
	
	print(doc)

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
