import sys
try:
	assert len(sys.argv) <= 2, "more than one argument is provided"
	if len(sys.argv) == 2:
		assert sys.argv[1].isnumeric(), "argument is not an integer"
		print(f"I'm {'Odd' if (int(sys.argv[1]) % 2) else 'Even'}")
except AssertionError as e:
	## this is stupid and dumb
	print(f"{type(e).__name__}: {e.args[0]}")
