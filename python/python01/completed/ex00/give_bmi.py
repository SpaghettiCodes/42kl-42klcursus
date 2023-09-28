import numpy as np


def give_bmi(height: list[int | float],
             weight: list[int | float]) -> list[int | float]:
    """
    Calculates the BMI of a list of height and weight

    The formula to calculate BMI is
            Weight / (height * height)

    @param  | height: list of heights
            | weight: list of weights

    @return | list of calculated BMI
    """
    if type(height) is not list or type(weight) is not list:
        print("ERROR! --- One of the parameter given is not a list!")
        return None

    height: np.array = np.array(height)
    weight: np.array = np.array(weight)

    result: np.array | None = None
    try:
        result = weight / (height ** 2)
    except TypeError:
        print("ERROR! --- One of the elements isnt a int or a float")
    except ValueError:
        print("ERORR! --- The list arent the same size")
    return None if result is None else result.tolist()


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    """
    Checks if elements in the bmi list is above the limit given

    @param  | bmi: list of bmi to check
            | limit: represents the limit

    @return | list of boolean, True if bmi is above limit, False if isn't
    """
    if type(bmi) is not list:
        print("ERROR! --- Parameter -BMI- given is not a list!")
        return None
    if not isinstance(limit, int | float):
        print("ERROR! --- Parameter -limit- given is not a float or a int!")
        return None
    if not all([isinstance(x, int | float) for x in bmi]):
        print("ERROR! --- There is a BMI value that isnt a int or float")
        return None

    result = np.array(bmi) > limit
    return result.tolist()


if __name__ == "__main__":
    # works
    ans = give_bmi([1, 2, 3], [4, 5, 6])
    print(ans)

    ans = apply_limit([1, 2, 3, 4, 5, 6, 7, 8], 3)
    print(ans)

    print("---error management---")

    # errors
    ans = give_bmi(1, 2)
    print(ans)

    ans = give_bmi("abcdefg", [1, 2, 3, 4])
    print(ans)

    ans = give_bmi("abcdefg", 2)
    print(ans)

    ans = give_bmi('a', 'b')
    print(ans)

    ans = give_bmi([1, 2, 3], [4, 5])
    print(ans)

    ans = apply_limit(1, 2)
    print(ans)

    ans = apply_limit([1, 2, 3, 4, 5], "abcdef")
    print(ans)
