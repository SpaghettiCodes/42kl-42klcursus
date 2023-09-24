from abc import ABC, abstractmethod
class Character(ABC):
	"""
	Character Abstract Class

	Cannot be Instantiated
	"""
	## this does not need to be a abstract method..
	@abstractmethod
	def __init__(self, first_name, is_alive=True) -> None:
		"""
		Initializes the values in the class
		"""
		self.firstname = first_name
		self.is_alive = is_alive

	## Neither does this tbh
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
		"""
		super().__init__(first_name, is_alive)