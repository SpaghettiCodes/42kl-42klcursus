def square(x: int | float) -> int | float:
    return x * x


def pow(x: int | float) -> int | float:
    return x ** x


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


if __name__ == "__main__":
    def cube(x: int | float) -> int | float:
        """Returns the cube of x"""
        return (x * x * x)
    my_counter = outer(6, square)
    print(my_counter())
    print(my_counter())
    print(my_counter())
    print("---")
    another_counter = outer(1.6, pow)
    print(another_counter())
    print(another_counter())
    print(another_counter())
    print("---")
    again_another_counter = outer(4, cube)
    print(again_another_counter())
    print(again_another_counter())
    print(again_another_counter())