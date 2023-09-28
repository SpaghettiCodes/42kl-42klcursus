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
    ob_type = type(object)
    if isinstance(object, str):
        print(f"{object} is in the kitchen : {ob_type}")
    elif isinstance(object, (list, tuple, set, dict)):
        print(f"{ob_type.__name__.capitalize()} : {ob_type}")
    else:
        print("Type not found")
    return 42
