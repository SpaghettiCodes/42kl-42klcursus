class calculator:
    """
    Calculator Class that has methods to calculate number stored
    inside
    """

    def __init__(self, tab: list) -> None:
        """
        Initializes the calculator class

        @param  | tab: the list of values to store
        """
        self.tab = tab
        if len(self.tab):
            self.type = type(self.tab[0])
        else:
            print("Empty Array Provided!")
            self.type = None

    def __iter(self, func, val) -> None:
        try:
            self.tab = [func(self.tab[index], val)
                        for index in range(len(self.tab))]
        except TypeError:
            return
        print(self.tab)

    def __add__(self, object) -> None:
        if self.type is None:
            print("ERROR! --- Empty array!")
            return
        try:
            self.__iter(self.type.__add__, object)
        except AttributeError:
            print("ERROR! --- Unsupported Operand For Type")

    def __mul__(self, object) -> None:
        if self.type is None:
            print("ERROR! --- Empty array!")
            return
        try:
            self.__iter(self.type.__mul__, object)
        except AttributeError:
            print("ERROR! --- Unsupported Operand For Type")

    def __sub__(self, object) -> None:
        if self.type is None:
            print("ERROR! --- Empty array!")
            return
        try:
            self.__iter(self.type.__sub__, object)
        except AttributeError:
            print("ERROR! --- Unsupported Operand For Type")

    def __truediv__(self, object) -> None:
        if self.type is None:
            print("ERROR! --- Empty array!")
            return
        try:
            self.__iter(self.type.__truediv__, object)
        except ZeroDivisionError as e:
            print(f"ERROR! --- {e}")
        except AttributeError:
            print("ERROR! --- Unsupported Operand For Type")

if __name__ == "__main__":
    # v1 = calculator([0.0, 1.0, 2.0, 3.0])
    # v1 + 5
    # v1 * 5
    # v1 - 5
    # v1 / 5

    v1 = calculator(['a', 'b', 'c', 'd'])
    v1 / 2
