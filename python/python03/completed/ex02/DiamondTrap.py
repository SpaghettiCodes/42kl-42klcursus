from S1E7 import Baratheon, Lannister


class King(Baratheon, Lannister):
    def __init__(self, first_name, is_alive=True) -> None:
        """
        Initializes the King object

        @param  | first_name = name of the King
                | is_alive = sets alive status, True by default
        """
        super().__init__(first_name, is_alive)

    def set_eyes(self, new_eyes) -> None:
        """
        Sets the eye of the King object to the parameter given

        @param  | new_eyes: new eye to set to
        """
        self.eyes = new_eyes

    def get_eyes(self) -> str:
        """
        Get the eye of the King object

        @return | the eyes of the King object
        """
        return self.eyes

    def set_hairs(self, new_hair) -> None:
        """
        Set the hair of the King object to the parameter given

        @param  | new_hair: new hair to set to
        """
        self.hairs = new_hair

    def get_hairs(self) -> str:
        """
        Gets the current hair of the King object to the parameter given

        @return | hair of the King object
        """
        return self.hairs
