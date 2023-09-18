import sys

NESTED_MORSE = {	\
	" " : "/ ",
	"A" : ".- ",
	"B" : "-... ",
	"C" : "-.-. ",
	"D" : "-.. ",
	"E" : ". ",
	"F" : "..-. ",
	"G" : "--. ",
	"H" : ".... ",
	"I" : ".. ",
	"J" : ".--- ",
	"K" : "-.- ",
	"L" : ".-.. ",
	"M" : "-- ",
	"N" : "-. ",
	"O" : "--- ",
	"P" : ".--. ",
	"Q" : "--.- ",
	"R" : "-.- ",
	"S" : "... ",
	"T" : "- ",
	"U" : "..- ",
	"V" : "...- ",
	"W" : ".-- ",
	"X" : "-..- ",
	"Y" : "-.-- ",
	"Z" : "--.. ",
	"0" : "----- ",
	"1" : ".---- ",
	"2" : "..--- ",
	"3" : "...-- ",
	"4" : "....- ",
	"5" : "..... ",
	"6" : "-.... ",
	"7" : "--... ",
	"8" : "---.. ",
	"9" : "----. ",
}

def main():
	allow_char = "abcdefghijklmnopqrstuvwxyz0123456789 "
	assert len(sys.argv) == 2 and all([(str.lower(x) in allow_char) for x in sys.argv[1]]), "the arguments are bad"
	print("".join([NESTED_MORSE[str.upper(char)] for char in sys.argv[1]]))

if __name__ == "__main__":
	main()