from load_csv import load

print(load("life_expectancy_years.csv"))
print()
print("----")

# errors below

print(type(load("not_a_csv.txt")))
print()
print("----")


print(type(load("fake_csv.csv")))
print()
print("----")


print(type(load("tester.py")))
print()
print("----")
