import sys

"""
Dictionary with the alphabet and its morse code equivalent
"""
NESTED_MORSE = {
    " ": "/",
    "A": ".-",
    "B": "-...",
    "C": "-.-.",
    "D": "-..",
    "E": ".",
    "F": "..-.",
    "G": "--.",
    "H": "....",
    "I": "..",
    "J": ".---",
    "K": "-.-",
    "L": ".-..",
    "M": "--",
    "N": "-.",
    "O": "---",
    "P": ".--.",
    "Q": "--.-",
    "R": ".-.",
    "S": "...",
    "T": "-",
    "U": "..-",
    "V": "...-",
    "W": ".--",
    "X": "-..-",
    "Y": "-.--",
    "Z": "--..",
    "0": "-----",
    "1": ".----",
    "2": "..---",
    "3": "...--",
    "4": "....-",
    "5": ".....",
    "6": "-....",
    "7": "--...",
    "8": "---..",
    "9": "----.",
}


def main():
    """
    main runner code that handles error management and conversion
    of normal alphabets to morse code equivalent
    """
    try:
        allow_char = "abcdefghijklmnopqrstuvwxyz0123456789 "
        assert len(sys.argv) == 2 and \
            all([(str.lower(x) in allow_char) for x in sys.argv[1]]), \
            "the arguments are bad"
    except AssertionError as e:
        print(f"AssertionError: {e}")
        return

    print(" ".join([NESTED_MORSE[str.upper(char)] for char in sys.argv[1]]))


if __name__ == "__main__":
    main()