from abc import ABC, abstractmethod


class Character(ABC):
    """
    Character Abstract Class

    Cannot be Instantiated
    """
    @abstractmethod
    def __init__(self, first_name, is_alive=True) -> None:
        """
        Initializes the values in the class

        @param  | first_name: name of the Character Object
                | is_alive: sets alive status, True by default
        """
        self.firstname = first_name
        self.is_alive = is_alive

    def die(self) -> None:
        """ Jesus christ the indentation is ugly
        Sets self.is_alive to False
        """
        self.is_alive = False


class Stark(Character):
    """
    Class that inherits from Character

    Can be Instantiated
    """

    def __init__(self, first_name, is_alive=True) -> None:
        """
        Initializes Stack Class variables

        Just calls Character's init

        @param  | first_name: name of the Character Object
                | is_alive: sets alive status, True by default
        """
        super().__init__(first_name, is_alive)