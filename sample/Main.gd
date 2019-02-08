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
	var doc = coll.find_one({})
	
	print(doc)

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
