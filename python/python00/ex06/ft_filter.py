# def ft_filter(function, iterable):
# 	if function == None:
# 		stuff = (value for value in iterable if value)
# 	else:
# 		stuff = (value for value in iterable if function(value))
# 	return stuff

def ft_filter(function, iterable):
	if function == None:
		stuff = [value for value in iterable if value]
	else:
		stuff = [value for value in iterable if function(value)]
	for values in stuff:
		yield values

if __name__ == "__main__":
	print(filter.__doc__)
	for x in ft_filter(str.isupper, "abcdefABCDEF"):
		print(x)