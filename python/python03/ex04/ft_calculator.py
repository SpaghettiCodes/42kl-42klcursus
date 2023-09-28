class calculator:
    @classmethod
    def dotproduct(cls, V1: list[float], V2: list[float]) -> None:
        result = sum([V1[index] * V2[index] for index in range(len(V1))])
        print(f"Dot product is: {result}")

    @classmethod
    def add_vec(cls, V1: list[float], V2: list[float]) -> None:
        result = [float(V1[index] + V2[index]) for index in range(len(V1))]
        print(f"Add Vector is : {result}")

    @classmethod
    def sous_vec(cls, V1: list[float], V2: list[float]) -> None:
        result = [float(V1[index] - V2[index]) for index in range(len(V1))]
        print(f"Sous Vector is : {result}")
