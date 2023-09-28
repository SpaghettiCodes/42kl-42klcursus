def count_in_list(to_check: list[any], object: any) -> int:
    """
    count_in_list(to_check: list[any], object: any) -> int

    counts the number of occurance of object in to_check

    @param	| to_check	: list to check
            | object	: object to find occurances of

    @return | number of occurances in to_check
    """
    return len([x for x in to_check if x == object])


if __name__ == "__main__":
    print(count_in_list(["toto", "tata", "toto"], "toto"))  # output: 2
    print(count_in_list(["toto", "tata", "toto"], "tutu"))  # output: 0
