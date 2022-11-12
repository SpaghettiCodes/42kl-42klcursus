import random

def generate(n):
    n = int(n)
    randomlist = []

    for i in range (0, n):
        repeated = 0
        while not repeated:
            add = random.randint(1, n)
            randomlist.append(add)
            checkset = set(randomlist)
            if len(randomlist) == len(checkset):
                repeated = 1
            else:
                randomlist.pop()

    for num in randomlist:
        print(str(num), end=" ")

    print("\n")

if __name__ == "__main__":
    generate(input("Number: "))