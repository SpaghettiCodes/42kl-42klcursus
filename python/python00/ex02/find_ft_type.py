def all_thing_is_obj(object: any) -> int:
	if isinstance(object, str):
		print(f"{object} is in the kitchen : {type(object)}")
	elif isinstance(object, (list, tuple, set, dict)):
		print(f"{type(object).__name__.capitalize()} : {type(object)}")
	else:
		print("Type not found")
	return 42

## cool runner codes
from find_ft_type import all_thing_is_obj

ft_list = ["Hello", "tata!"]
ft_tuple = ("Hello", "toto!")
ft_set = {"Hello", "tutu!"}
ft_dict = {"Hello" : "titi!"}

all_thing_is_obj(ft_list)
all_thing_is_obj(ft_tuple)
all_thing_is_obj(ft_set)
all_thing_is_obj(ft_dict)
all_thing_is_obj("Brian")
print(all_thing_is_obj(10))