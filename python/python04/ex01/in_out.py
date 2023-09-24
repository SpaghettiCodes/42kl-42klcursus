def square(x: int | float) -> int | float:
	return x * x

def pow(x: int | float) -> int | float:
	return x ** x

"""
Took an embarassing long time on this :P

https://www.learnbyexample.org/python-nonlocal-keyword/#:~:text=If%20a%20variable%20is%20declared,primarily%20used%20in%20nested%20functions.

nonlocal keyword

a function inside a function cannot change the value 
of a variable in its parent function due to different scope

this is because when you create a variable in the nested function,
python creates a new local variable which shadows the variable in 
the outer scope

the outer function and inner function are 2 different scopes

To prevent this behavior, you use nonlocal

nonlocal tells python that this variable reference a variable
that is in the outer scope

so python does not create a new local variable, and does not shadow the variable
in the outer scope
"""
def outer(x: int | float, function) -> object:
	count = 0
	def inner() -> float:
		nonlocal count
		count += 1
		ret = x
		for _ in range(count):
			ret = function(ret)
		return ret
	return inner