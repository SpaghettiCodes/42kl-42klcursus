from load_image import ft_load

import numpy as np
import matplotlib.pyplot as plt


def cutSquare(data: np.ndarray, top_right: tuple[float],
              new_dimensions: tuple[float]) -> np.ndarray:
    """
    "Cuts" out a square from the image
    and return the new image with the new dimensions

    @param  | data: data on the original image
            | top_right:    coordinates of the top right of the
            |               new image, in the old image
            | new_dimensions: the new dimensions of the new image

    @return | the new image with the new dimensions
    """
    x = top_right[0]
    y = top_right[1]
    diff_x = new_dimensions[0]
    diff_y = new_dimensions[1]
    return data[x:x + diff_x:, y:y + diff_y:, 0]


def transpose(data: np.ndarray):
    """
    Transposes the array

    a (M x N) matrix, after transposing, will become (N x M)
    the matrix is flipped over its diagonal, all
    rows and column indices are switched

    @param  | data: matrix to transpose

    @return | transposed array
    """
    columns = data.shape[1]

    ret = [data[::, x] for x in range(columns)]
    return np.array(ret)


def main():
    """
    main runner code with error handling
    """
    np.set_printoptions(edgeitems=3)
    data = ft_load("animal.jpeg")
    if data is None:
        return

    data = cutSquare(data, (100, 450), (400, 400))

    print("New Shape after slicing:", data.shape)
    print(data)

    data = transpose(data)

    # the pdf method of printing shows NOTHING about the
    # difference between normal and transposing
    # sooo
    print("New Shape after Transpose:", data.shape)
    print(data)

    plt.imshow(data, cmap="gray")
    plt.show()


if __name__ == "__main__":
    main()
