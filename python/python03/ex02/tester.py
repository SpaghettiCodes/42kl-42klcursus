# from DiamondTrap import King

# Joffrey = King("Joffrey")
# print(Joffrey.__dict__)
# Joffrey.set_eyes("blue")
# Joffrey.set_hairs("light")
# print(Joffrey.get_eyes())
# print(Joffrey.get_hairs())
# print(Joffrey.__dict__)

from DiamondTrap import King
from S1E7 import Baratheon, Lannister
from S1E9 import Character

Joffrey = King("Joffrey")
print(Joffrey.__dict__)
print(Joffrey.__doc__)
Joffrey.set_eyes("blue")
Joffrey.set_hairs("light")
print(Joffrey.__dict__)
if (isinstance(Joffrey, King) and issubclass(King, Character) and issubclass(King, Lannister) and issubclass(King, Baratheon)):
    print("OK")
else:
    print("Something seems fishy, look at the code to see if the class king is inherited from the previous exercises")
