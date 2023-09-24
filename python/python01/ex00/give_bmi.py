import numpy as np

def give_bmi(height: list[int | float], weight: list[int | float]) -> list[int | float]:
	height: np.array = np.array(height)
	weight: np.array = np.array(weight)

	result: np.array | None = None
	try:
		result = weight / (height ** 2)
	except TypeError:
		print("ERROR! --- One of the elements isnt a int or a float")
	except ValueError:
		print("ERORR! --- The list arent the same size")
	return None if result is None else result.tolist()

def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
	if not all([isinstance(x, int | float) for x in bmi]):
		print("ERROR! --- There is a bmi value that isnt a int or float")
		return None

	result = np.array(bmi) > limit
	return result.tolist()
