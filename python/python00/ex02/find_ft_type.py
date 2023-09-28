def all_thing_is_obj(object: any) -> int:
    """
    Determine the object type and then prints it out

    if object is not a
            - str
            - list
            - tuple
            - set
            - dict

    It prints out Type not Found instead

    :return | the value 42
    """
    if isinstance(object, str):
        print(f"{object} is in the kitchen : {type(object)}")
    elif isinstance(object, (list, tuple, set, dict)):
        print(f"{type(object).__name__.capitalize()} : {type(object)}")
    else:
        print("Type not found")
    return 42
