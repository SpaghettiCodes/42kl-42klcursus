from load_image import ft_load

import numpy as np
import matplotlib.pyplot as plt


def cutSquare(data: np.ndarray, top_right: tuple[float],
              new_dimensions: tuple[float]) -> np.ndarray:
    """
    "Cuts" out a square from the image
    and return the new image with the new dimensions

    zooming in results the "gb" channel from the RGB removed
    i do not know why this is the case, ask the pdf
    its completely possible to zoom in while keeping the entire
    RGB

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


def main():
    """
    main runner code with error handling
    """
    np.set_printoptions(edgeitems=3)
    data = ft_load("animal.jpeg")
    if data is None:
        return

    data_shape = data.shape
    print(data.reshape(1, data_shape[0] * data_shape[1], data_shape[2]))

    data = cutSquare(data, (100, 450), (400, 400))
    print("New Shape after slicing:", data.shape)

    data_shape = data.shape
    print(data.reshape(1, data_shape[0] * data_shape[1], 1))

    plt.imshow(data, cmap="gray")
    plt.show()


if __name__ == "__main__":
    main()
