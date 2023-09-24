class calculator:
	def __init__(self, tab: list) -> None:
		self.tab = tab
		if len(self.tab):
			self.type = type(self.tab[0])
		else:
			print("Empty Array Provided!")
			self.type = None

	def __iter(self, func, val) -> None:
		self.tab = [func(self.tab[index], val) for index in range(len(self.tab))]
		print(self.tab)

	def __add__(self, object) -> None:
		self.__iter(self.type.__add__, object)

	def __mul__(self, object) -> None:
		self.__iter(self.type.__mul__, object)

	def __sub__(self, object) -> None:
		self.__iter(self.type.__sub__, object)

	def __truediv__(self, object) -> None:
		try:
			self.__iter(self.type.__truediv__, object)
		except ZeroDivisionError as e:
			print(f"ERROR! --- {e}")
