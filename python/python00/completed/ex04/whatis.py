import sys


def canbe_int(test: str) -> bool:
    """
    Test if string input is an integer

    :param	| test: string to test

    :return	| True if string is an integer value, false if it isnt
    """
    try:
        int(test)
    except ValueError:
        return False
    return True


def main():
    """
    main runner code
    """
    try:
        assert len(sys.argv) <= 2, "more than one argument is provided"
        if len(sys.argv) == 2:
            assert canbe_int(sys.argv[1]), "argument is not an integer"
            print(f"I'm {'Odd' if (int(sys.argv[1]) % 2) else 'Even'}")
    except AssertionError as e:
        print(f"{type(e).__name__}: {e.args[0]}")


if __name__ == "__main__":
    main()
