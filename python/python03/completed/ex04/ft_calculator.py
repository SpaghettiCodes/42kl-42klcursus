class calculator:
    @classmethod
    def dotproduct(cls, V1: list[float], V2: list[float]) -> None:
        """
        Calculates the dot product between 2 Vectors
        Then print out the result
        """
        result = sum([V1[index] * V2[index] for index in range(len(V1))])
        print(f"Dot product is: {result}")

    @classmethod
    def add_vec(cls, V1: list[float], V2: list[float]) -> None:
        """
        Adds 2 vectors together
        Then print out the result
        """
        result = [float(V1[index] + V2[index]) for index in range(len(V1))]
        print(f"Add Vector is : {result}")

    @classmethod
    def sous_vec(cls, V1: list[float], V2: list[float]) -> None:
        """
        Substract 2 vector together
        Then print out the result
        """
        result = [float(V1[index] - V2[index]) for index in range(len(V1))]
        print(f"Sous Vector is : {result}")
