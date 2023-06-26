
while not isteenager:
	try:
		age = int(input("enter your age: "))
		if age >= 13 and age <= 19:
			isteenager = True
		else:
			print("Invalid Age: Age is not between 13 and 19!")
	except:
		print("Invalid Age : Input is not numeric!")

# ALTERNATIVELY

while not isteenager:
	age = input("enter your age: ")
	if age.isnumeric():
		if int(age) >= 13 and int(age) <= 19:
			isteenager = True
		else
			print("Invalid Age: Age is not between 13 and 19!")
	else:
		print("Invalid Age: Input is not numeric!")

# OR

while not isteenager:
	age = input("enter your age: ")
	if not age.isnumeric():
		print("Invalid Age: Input is not numeric!")
	if int(age) >= 13 and int(age) <= 19:
		isteenager = True
	else
		print("Invalid Age: Age is not between 13 and 19!")

