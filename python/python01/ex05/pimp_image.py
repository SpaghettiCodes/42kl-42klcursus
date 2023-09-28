import numpy as np


def ft_invert(array: np.ndarray) -> np.ndarray:
    """
    Inverts the color of the image received

    @param  | array: original image array

    @return | new array representing the image with it's color inverted
    """

    return abs(array.copy() - 255)


def ft_red(array: np.ndarray) -> np.ndarray:
    """
    Applies a red filter on the image

    @param  | array: original image array

    @return | new array representing the image with red filter
    """

    return array.copy() * [1, 0, 0]


def ft_green(array: np.ndarray) -> np.ndarray:
    """
    Applies a green filter on the image

    @param  | array: original image array

    @return | new array representing the image with green filter
    """

    ret = array.copy()
    ret[:, :, (0, 2)] = 0
    return ret


def ft_blue(array: np.ndarray) -> np.ndarray:
    """
    Applies a blue filter on the image

    @param  | array: original image array

    @return | new array representing the image with blue filter
    """

    ret = array.copy()
    ret[:, :, (0, 1)] = 0
    return ret


def ft_grey(array: np.ndarray) -> np.ndarray:
    """
    Changes the image to be grayscale

    @param  | array: original image array

    @return | new array representing the grayscaled image
    """

    # https://stackoverflow.com/questions/39441517/in-numpy-sum-there-is-parameter-called-keepdims-what-does-it-do
    ret: np.ndarray = array.mean(axis=2, dtype="int", keepdims=True)
    ret = ret.repeat(repeats=3, axis=2)

    # ret: np.ndarray = array.sum(axis=2, keepdims=True) // 3
    # ret = ret.repeat(repeats=3, axis=2)
    return ret
