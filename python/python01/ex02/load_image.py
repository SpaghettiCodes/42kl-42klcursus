import PIL
from PIL import Image
import numpy as np


def ft_load(path: str) -> np.array:
    """
    Loads an image based on the path given

    Prints the format and pixels content in RGB format

    @param  | path: path of the file to be opened
    @return | array of the loaded image, RGB format
    """
    try:
        img = Image.open(path)
    except FileNotFoundError:
        print("ERROR! --- File Not Found!")
        return None
    except PIL.UnidentifiedImageError:
        print("ERROR! --- Unable to Identify Image!")
        return None

    img.load()
    data = np.asarray(img, dtype="int32")
    print("The shape of the image is:", data.shape)
    return data
