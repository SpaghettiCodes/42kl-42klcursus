def ft_filter(function, iterable):
    """filter(function or None, iterable) --> filter object

Return an iterator yielding those items of iterable for which function(item)
is true. If function is None, return the items that are true."""
    if function is None:
        stuff = [value for value in iterable if value]
    else:
        stuff = [value for value in iterable if function(value)]
    return stuff


if __name__ == "__main__":
    print(ft_filter.__doc__ == filter.__doc__)
    for x in ft_filter(str.isupper, "abcdefABCDEF"):
        print(x)
