class calculator:
	@classmethod
	def dotproduct(cls, V1: list[float], V2: list[float]) -> None:
		print(f"Dot product is: {sum([V1[index] * V2[index] for index in range(len(V1))])}") 


	@classmethod
	def add_vec(cls, V1: list[float], V2: list[float]) -> None:
		print(f"Add Vector is : {[float(V1[index] + V2[index]) for index in range(len(V1))]}")
		

	@classmethod
	def sous_vec(cls, V1: list[float], V2: list[float]) -> None:
		"""
		SOUP VEC
		SOUP
		HASTA LA VISTA SOUP
		"""
		print(f"Sous Vector is : {[float(V1[index] - V2[index]) for index in range(len(V1))]}")
