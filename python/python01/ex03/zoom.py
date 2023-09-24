from load_image import ft_load

import numpy as np
import matplotlib.pyplot as plt 

def main():
	np.set_printoptions(edgeitems=3)
	data = ft_load("animal.jpeg")
	if data is None:
		return
	print(data)

	## this .reshape() allows you to achieve the 
	## print format as shown in the pdf
	# data_shape = data.shape
	# print(data.reshape(1,data_shape[0] * data_shape[1],data_shape[2]))

	data = data[100:500:, 450:850:, 0:1]
	print("New Shape after slicing:", data.shape)
	print(data)

	# data_shape = data.shape
	# print(data.reshape(1,data_shape[0] * data_shape[1],data_shape[2]))

	## We truncated the array so that it only has 1 Channel now
	## Its only a (M x N) image
	## use cmap to make it gray instead
	plt.imshow(data, cmap="gray")
	plt.show()

if __name__ == "__main__":
	main()