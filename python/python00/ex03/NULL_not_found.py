def NULL_not_found(object: any) -> int:
	"""
	Determines if an object is equivalent to NULL
	Prints out a specific keyword (why is NaN Cheese), the value and the object's type
	Prints out Type not Found if it isnt a NULL / Type not included (sad empty list sounds)

	because somehow NaN is NULL now

	:para,	| object : object to test

	:return	| 0 if succesful (hah, get it, cause 0 is NULL as well), 1 if failed
	"""
	if object is None:
		name = 'Nothing'
	elif object != object:
		name = 'Cheese'
	elif object is False:
		name = 'Fake'
	elif object == '':
		name = 'Empty'
	elif object == 0:
		name = 'Zero'
	else:
		print('Type not Found')
		return 1

	print(f"{name}: {object} {type(object)}")
	return 0
