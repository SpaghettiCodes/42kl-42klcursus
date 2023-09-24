from math import sqrt

## HAHA this is in python standard module BABY

def mean(num_tab):
	return sum(num_tab) / len(num_tab)

def median(num_tab):
	return num_tab[len(num_tab) // 2] if len(num_tab) % 2 else (num_tab[len(num_tab) // 2] + num_tab[(len(num_tab) // 2) + 1]) / 2

def quartile(num_tab):
	first_index = len(num_tab) // 4
	second_index = len(num_tab) * 3 // 4
	if len(num_tab) % 2:
		first_quartile = num_tab[first_index]
		second_quartile = num_tab[second_index]
	else:
		first_quartile = mean([num_tab[first_index], num_tab[first_index + 1]])
		second_quartile = mean([num_tab[second_index], num_tab[second_index + 1]])
	return [float(first_quartile), float(second_quartile)]

def std(num_tab):
	return sqrt(var(num_tab))

def var(num_tab):
	## MOSSOM 
	## Mean of Squared - Square of Mean
	return mean([var ** 2 for var in num_tab]) - (mean(num_tab) ** 2)

def ft_statistics(*args: any, **kwargs: any) -> None:
	num_tab = list(args)
	if not all([isinstance(var, int | float) for var in num_tab]):
		print("ERROR --- Invalid Parameters!")
		return

	num_tab.sort()

	functions = [mean, median, quartile, std, var]
	function_dict = {func.__name__ : func   for func in functions}
	for value in kwargs.values():
		if function_dict.get(value.lower(), None):
			if len(num_tab):
				print(f"{value.lower()} : {function_dict[value.lower()](num_tab)}")
			else:
				print("ERROR")