import sys
from ft_filter import ft_filter

def main():
	assert len(sys.argv) == 3 and sys.argv[2].isdigit(), "the arguments are bad"
	word_full = sys.argv[1].split(' ')
	word_list = list(ft_filter((lambda x: len(x) > int(sys.argv[2])), word_full))
	print(word_list)

if __name__ == "__main__":
	main()