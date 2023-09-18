def NULL_not_found(object: any) -> int:
	if object:
		# HOW IS NAN COUNTED AS NULL
		# WTF

		# WHY DOES NAN != NAN
		# WTF
		if isinstance(object, float) and object != object:
			print(f"Cheese: {object} {type(object)}")
			return 0
		else:
			print("Type not Found")
			return 1
			
	varname = [var for var in globals().keys() if (isinstance(globals()[var], type(object))) and (object is globals()[var])]
	varname = [var for var in varname if var.find('__') == -1]
	print(f"{varname[0]}: {object} {type(object)}")
	return 0

## test code
## MUST be here in order for the stupid var name finder to work

Nothing = None
Garlic = float("NaN")
Zero = 0
Empty = ""
Fake = False

NULL_not_found(Nothing)
NULL_not_found(Garlic)
NULL_not_found(Zero)
NULL_not_found(Empty)
NULL_not_found(Fake)
print(NULL_not_found("Brian"))