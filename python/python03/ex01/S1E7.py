from S1E9 import Character


class Baratheon(Character):
    def __init__(self, first_name, is_alive=True) -> None:
        """
        Initializes the values in the class

        @param  | first_name: name of the Baratheon Object
                | is_alive: sets alive status, True by default
        """
        self.first_name = first_name
        self.is_alive = is_alive

        self.family_name = "Baratheon"
        self.eyes = "brown"
        self.hairs = "dark"

    def __str__(self) -> str:
        """Returns string representation of object"""
        return "Hi!"

    def __repr__(self) -> str:
        """Returns a representation of the object"""
        return f"Vector: ('{self.family_name}', '{self.eyes}', '{self.hairs}')"


class Lannister(Character):
    def __init__(self, first_name, is_alive=True) -> None:
        self.first_name = first_name
        self.is_alive = is_alive

        self.family_name = "Lannister"
        self.eyes = "blue"
        self.hairs = "light"

    def __str__(self) -> str:
        """Returns string representation of object"""
        return "Hoi!"

    def __repr__(self) -> str:
        """Returns representation of the object"""
        return f"Vector: ('{self.family_name}', '{self.eyes}', '{self.hairs}')"

    @classmethod
    def create_lannister(cls, first_name, is_alive=True):
        """
        A Class method to create a new instance of a Lannister object

        @param  | first_name: name of the Baratheon Object
                | is_alive: sets alive status, True by default

        @return | new Lannister object
        """
        return Lannister(first_name, is_alive)
