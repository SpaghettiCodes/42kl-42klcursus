from math import sqrt


def mean(num_tab):
    return sum(num_tab) / len(num_tab)


def median(num_tab):
    index = int((len(num_tab) + 1) * 1/2) - 1
    if len(num_tab) % 2:
        return (num_tab[index])
    else:
        return (num_tab[index] + num_tab[index + 1]) / 2

# https://www.calculatorsoup.com/calculators/statistics/quartile-calculator.php
# i forgot how quartile is calculated


def quartile(num_tab):
    if len(num_tab) % 2:  # odd
        split = len(num_tab) // 2
        lq, uq = median(num_tab[0:split]), median(num_tab[split+1:])
    else:  # even
        split = int((len(num_tab) / 2))
        lq, uq = median(num_tab[0:split]), median(num_tab[split:])
    return [lq, uq]


def std(num_tab):
    return sqrt(var(num_tab))


def var(num_tab):
    # MOSSOM
    # Mean of Squared - Square of Mean
    return mean([var ** 2 for var in num_tab]) - (mean(num_tab) ** 2)


def ft_statistics(*args: any, **kwargs: any) -> None:
    num_tab = list(args)
    if not all([isinstance(var, int | float) for var in num_tab]):
        print("ERROR --- Invalid Parameters!")
        return

    num_tab.sort()

    functions = [mean, median, quartile, std, var]
    function_dict = {func.__name__: func for func in functions}
    for value in kwargs.values():
        value = value.lower()
        if function_dict.get(value, None):
            if len(num_tab):
                print(
                    f"{value} : {function_dict[value](num_tab)}")
            else:
                print("ERROR")


if __name__ == "__main__":
    ft_statistics(1, 42, 360, 11, 64, toto="mean",
                  tutu="median", tata="quartile")
    print("-----")
    ft_statistics(5, 75, 450, 18, 597, 27474, 48575,
                  hello="std", world="var")
    print("-----")
    ft_statistics(5, 75, 450, 18, 597, 27474, 48575,
                  ejfhhe="heheh", ejdjdejn="kdekem")
    print("-----")
    ft_statistics(toto="mean", tutu="median", tata="quartile")

    # quartile tester
    print("--- testing quartile ---")
    hehe = [0, 1, 2]
    for x in range(3, 14):
        hehe.append(x)
        stuff = str(hehe).strip('[]')
        print(stuff)
        eval(f"ft_statistics( {stuff} , stuff=\"quartile\")")
        print()
