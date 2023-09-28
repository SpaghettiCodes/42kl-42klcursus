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

    # keepdims tries to keep original dimensions of the input array
    # so if input array is like
    # [[1,2,3]
    # [4,5,6]
    # [7,8,9]]
    # instead of [2,7.5,12]
    # it will be [[2], [7.5], [12]]
    # which maintains the original dimensions of (3x3) => (3x1) instead of
    # (3x3) => (3)
    ret: np.ndarray = array.mean(axis=2, dtype="int", keepdims=True)
    ret = ret.repeat(repeats=3, axis=2)

    return ret
