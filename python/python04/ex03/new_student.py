import random
import string
from dataclasses import dataclass, field

"""
Dataclasses
-----------------------
I never heard of these in my entire life!

Provides a decorator and functions to automatically generate special methods such as
    - __init__
    - __repr__
    - __str__


A Dataclass of

@dataclass
class shit:
    stuff: str
    stuff2: str
    stuff3: float = 10

will have a __init__ function of

def __init__(self, stuff: str, stuff2: str, stuff3: float = 10):
    self.stuff = stuff
    self.stuff2 = stuff2
    self.stuff3 = stuff3

-----------------------------------------------------------

@dataclasses.dataclass(*, init=True, repr=True, eq=True, order=False, unsafe_hash=False, frozen=False, match_args=True, kw_only=False, slots=False, weakref_slot=False)
Will add the generated special emthods to the class

init - __init__()

repr - __repr__()

eq - __eq__()

order - lt, le, gt, ge will be generated

unsafe_hash -	IF FALSE, __hash__ will be generated according to how eq and frozen are set (hash is for dictionary and sets)
                dataclass will not impicitly add a __hash__ unless if it is safe to do so
                can be forced to create a hash by setting this True
                having eq and frozen both true will make dataclass generate a __hash__ automatically

frozen -	assigning to fields will generate an exception
            Read Only Frozen instances
            having __setattr__ and __delattr__ causes TypeError to be raised

match_args -	__match_args__ tuple will be created from the list of parameters to the generated __init__
                will not be generated if __match_args__ is already defined, or if set to False

kw_only -	all fields will be marked as keyword-only
                kw_only --> __init__ parameter generated from a kw-only field must be specified with a keyword
                i have no idea what does this means, better check KW_ONLY later

                update -> it means the parameters must be specified as keyword in __init__

                so like

                class stuff:
                    x: float
                    _: KW_ONLY
                    y: float <== Starting from this variable, all variable needs to specify the keyword
                    z: float

                stuff(0, y=1.5, z=1.5) <== y and z keyword specified

            More about keyword_arguments = https://medium.com/analytics-vidhya/keyword-only-arguments-in-python-3c1c00051720
            https://peps.python.org/pep-3102/

fields can specify a default value

@dataclass
class C:
    a: int
    b: int = 0 # default value of b is 0

-----------------------------------------------------------

dataclasses.field(*, default=MISSING, default_factory=MISSING, init=True, repr=True, hash=None, compare=True, metadata=None, kw_only=MISSING)

for additional information aside from default value, this can be called instead

Parameters

default -> default value of the field
default_factory ->	zero-argument function
                    will be called when a default value is needed for the field
                    CANNOT be specified together with default
init -> included as parameter in the __init__ method
        false == CANNOT BE INIT
repr -> included as part of the string returned by repr

hash -> This field is included for hashing (__hash__)

-----------------------------------------------------------
"""


def generate_id() -> str:
    return "".join(random.choices(string.ascii_lowercase, k=15))


@dataclass
class Student:
    name: str
    surname: str
    active: bool = True  # assign a default value for active
    login: str = field(init=False)
    id: str = field(default_factory=generate_id, init=False)

    def __post_init__(self):
        self.login = f'{self.name[0]}{self.surname}'
