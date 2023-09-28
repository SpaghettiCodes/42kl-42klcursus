import sys
from ft_filter import ft_filter


def main():
    """
    main code runner with error handling for argc argv
    """
    try:
        assert len(sys.argv) == 3 and sys.argv[2].isnumeric(
        ), "the arguments are bad"
    except AssertionError as e:
        print(f"AssertionError: {e}")
        return

    word_full = sys.argv[1].split(' ')
    word_list = [item for item in ft_filter(
        (lambda x: len(x) > int(sys.argv[2])), word_full)]
    print(word_list)


if __name__ == "__main__":
    main()
