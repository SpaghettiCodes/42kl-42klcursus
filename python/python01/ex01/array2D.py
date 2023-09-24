import numpy as np

def slice_me(family: list, start: int, end: int) -> list:
	if type(family) is not list:
		print("ERROR! --- Not a list")
		return None

	family: np.array = np.array(family)
	print("My shape is :", family.shape)
	ret = family[start:end]
	print("My new shape is :", ret.shape)
	return ret.tolist()
