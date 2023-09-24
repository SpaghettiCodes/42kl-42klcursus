from load_image import ft_load

import numpy as np
import matplotlib.pyplot as plt 

## centre = (x,y)
def cutSquare(data: np.ndarray, top_right: tuple[float], new_dimensions: tuple[float]):
	x = top_right[0]
	y = top_right[1]
	diff_x = new_dimensions[0]
	diff_y = new_dimensions[1]
	return data[x:x + diff_x:, y:y + diff_y:, 0]


def transpose(data: np.ndarray):
	columns = data.shape[1]

	ret = [data[::, x] for x in range(columns)]
	return np.array(ret)


def main():
	np.set_printoptions(edgeitems=3)
	data = ft_load("animal.jpeg")
	if data is None:
		return

	data = cutSquare(data, (100, 450), (400, 400))
	print("New Shape after slicing:", data.shape)
	print(data)

	data = transpose(data)
	print("New Shape after Transpose:", data.shape)
	print(data)

	plt.imshow(data, cmap="gray")
	plt.show()

if __name__ == "__main__":
	main()