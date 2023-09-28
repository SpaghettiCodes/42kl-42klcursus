ft_list = ["Hello", "tata!"]
ft_tuple = ("Hello", "toto!")
ft_set = {"Hello", "tutu!"}
ft_dict = {"Hello": "titi!"}

# list are mutable
ft_list[1] = "World!"
# tuples are not mutable
store = list(ft_tuple)
store[1] = 'Malaysia!'
ft_tuple = tuple(store)
# sets are not ordered
# no [] accessing since not ordered
# output will be different every time you run it
ft_set.remove('tutu!')
ft_set.add('Subang Jaya!')
# dictionary values are mutable
ft_dict["Hello"] = "42KL!"

print(ft_list)
print(ft_tuple)
print(ft_set)
print(ft_dict)
