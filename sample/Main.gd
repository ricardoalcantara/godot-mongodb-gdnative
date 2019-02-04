extends Node

# Declare member variables here. Examples:
# var a = 2
# var b = "text"

# Called when the node enters the scene tree for the first time.
func _ready():
#	instantiating a GDNative class
	var test = load("res://bin/gdmongodb.gdns").new()
	print(test.hello_world())
#	print($Node.hello_world())
	pass

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
