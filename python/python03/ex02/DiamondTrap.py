from S1E7 import Baratheon, Lannister

class King(Baratheon, Lannister):
	def __init__(self, first_name, is_alive=True) -> None:
		## honestly no idea how old python works
		## but its fucked
		## and inheritance is wonky in python anyways


		## the order of __init__ is calculated using "depth-first left-to-right traversal"
		## super().__init__() provides the next __init__ method accoding to the MRO algorithm
		## you can check the order (Method Resolution Order MRO) by class.__mro__		

		## Check test/ for examples


		## https://stackoverflow.com/questions/46199975/resolving-diamond-inheritance-within-python-classes
		## https://www.geeksforgeeks.org/drop-rows-from-the-dataframe-based-on-certain-condition-applied-on-a-column/

		## oh this one is really good
		## https://stackoverflow.com/questions/3277367/how-does-pythons-super-work-with-multiple-inheritance

		## http://python-history.blogspot.com/2010/06/method-resolution-order.html
		## this has a good example on the diamond issue
		
		## if D inherits B, C, and both B C inherit A
		## and if A has a method "save", and C has a method "save", but B does not 
		## D will inherit A's save and not C's "save" because D -> B -> A (save is here) -> C (using classic MRO)
		super().__init__(first_name, is_alive)
	
	def set_eyes(self, new_eyes) -> None:
		self.eyes = new_eyes

	def get_eyes(self) -> str:
		return self.eyes

	def set_hairs(self, new_hair) -> None:
		self.hairs = new_hair

	def get_hairs(self) -> str:
		return self.hairs