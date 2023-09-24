import PIL
from PIL import Image
import numpy as np

def ft_load(path: str) -> np.array:
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
	return data