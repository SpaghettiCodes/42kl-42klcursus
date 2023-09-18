import sys

def main() -> None:
	assert len(sys.argv) <= 2, "Fuck You"
	if len(sys.argv) == 2:
		process_me = sys.argv[1]
	else:
		print("What is the text to count?")
		## has input(), reads stdin like cavemen
		process_me = sys.stdin.readline()

	total_len = len(process_me)
	total_upper = len(list(filter(str.isupper, process_me)))

	total_lower = len(list(filter(str.islower, process_me)))
	total_digit = len(list(filter(str.isdigit, process_me)))
	total_spaces = len(list(filter(str.isspace, process_me)))
	remaining = total_len - total_upper - total_lower - total_digit - total_spaces 

	print(f"The text contains {total_len} characters")
	print(f"{total_upper} upper letters")
	print(f"{total_lower} lower letters")
	print(f"{remaining} punctuation marks")
	print(f"{total_spaces} spaces")
	print(f"{total_digit} digits")

if __name__ == "__main__":
	main()