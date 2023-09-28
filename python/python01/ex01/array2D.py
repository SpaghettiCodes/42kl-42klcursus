import numpy as np


def slice_me(family: list, start: int, end: int) -> list:
    """
    Prints the shape of the array, the slices the array
    into a smaller shape based on parameters given

    @param  | family: a list
            | start: beginning index of list
            | end: end index of list, will not include end

    @return | truncated version of array based on
            | start and end
    """
    if type(family) is not list:
        print("ERROR! --- Not a list")
        return None

    family: np.array = np.array(family)
    print("My shape is :", family.shape)
    ret = family[start:end]
    print("My new shape is :", ret.shape)
    return ret.tolist()
