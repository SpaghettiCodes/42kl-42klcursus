import sys


def get_statistics(string: str):
    """
    Calculate certain statistic in the string

    - The total length
    - The total upper-case characters
    - The total lower-case characters
    - Whitespaces
    - The total punctuation symbols used
        (which is basically just [length - upper - lower - white])

    Then, prints out the statistics

    :param	| string : the string to calculate statistics from
    """

    total_len = len(string)
    total_upper = len(list(filter(str.isupper, string)))
    total_lower = len(list(filter(str.islower, string)))
    total_digit = len(list(filter(str.isdigit, string)))
    total_spaces = len(list(filter(str.isspace, string)))
    remaining = total_len - total_upper - \
        total_lower - total_digit - total_spaces

    print_statistics(total_len, total_upper, total_lower,
                     remaining, total_spaces, total_digit)


def print_statistics(total_len, total_upper, total_lower,
                     total_punctuations, total_spaces, total_digit):
    """
    Prints out results of statistics of a string
    Gotten from get_statistics
    """
    print(f"The text contains {total_len} characters")
    print(f"{total_upper} upper letters")
    print(f"{total_lower} lower letters")
    print(f"{total_punctuations} punctuation marks")
    print(f"{total_spaces} spaces")
    print(f"{total_digit} digits")


def main() -> None:
    """
    main code runner with error handling
    """
    try:
        assert len(sys.argv) <= 2, "more than one argument are provided"
    except AssertionError as e:
        print(f"Assertion Error: {e}")
        return

    if len(sys.argv) == 2:
        process_me = sys.argv[1]
    else:
        print("What is the text to count?")
        process_me = sys.stdin.readline()

    get_statistics(process_me)


if __name__ == "__main__":
    main()
