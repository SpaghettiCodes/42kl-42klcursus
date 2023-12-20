"""
Wrappers, Function decorator

https://www.artima.com/weblogs/viewpost.jsp?thread=240845#decorator-functions-with-decorator-arguments

A function that takes another function and extends the
behavior of the latter function without
explicitly modifying it

for example: a decorator that add 1 to the return value of any function

def add_one_dec(func):
    def add_one():
        value = func()a
        return value + 1
    return add_one

def example_function():
    return 1

final_value = add_one_dec(example_function) <--- a very simple decorator
print(final_value())

when add_one_dec is called, it creates a new function (add_one)
this function is then stored in final_value

if we call final_value -> add_one is called -> func (example_function) is called

The ampesand symbol (did i spell it correctly) @

the @ symbol simplifies this by a lot

@add_one_deco
def example_function():
    return 1

doing this is equivalent to doing :-
example_function = add_one_deco(example_function)

so every time example_function is called, add_one_deco will be called, which means add_one will be called

Passing Arguments with decorators

def add_one_deco(func):
    def add_one(*args, **kwargs):
        value = func(*args, **kwargs)
        return value + 1
    return add_one

add_one should be able to receive any amount of positional
arguments and keyword arguments

*args -> positional arguments
**kwargs -> keyword arguments

One way to think about it is

@decorator
def foo(*args, **kwargs)
    pass

is equivalent to -

foo = decorator(foo)

and

@decorator(arg)
def foo(*args, **kwargs)
    pass

is equivalent to

foo = decorator(arg)(foo)

The syntax for decorators is as follow:

def decorator_factory(argument):
    def decorator(function):
        def wrapper(*args, **kwargs):
            funny_stuff()
            something_with_argument(argument)
            result = function(*args, **kwargs)
            more_funny_stuff()
            return result
        return wrapper
    return decorator

is equivalent to

function = decorator_factory(argument)(function)
--> function = decorator(function)
--> function = wrapper(*functions's args, **function's kwargs) <-- wrapper calls function inside

"""


def callLimit(limit: int):
    count = 0

    def callLimiter(function):
        def limit_function(*args: any, **kwds: any):
            nonlocal count
            count += 1
            if count > limit:
                print(f"{function} call too many times")
            else:
                function(*args, **kwds)
        return limit_function
    return callLimiter
