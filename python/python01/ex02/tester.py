from load_image import ft_load

# work
print(type(ft_load("landscape.jpg")))

# doesnt work
print(type(ft_load("corrupt.jpg")))

print(type(ft_load("test.text")))

print(type(ft_load("awhdiawhdihai")))
