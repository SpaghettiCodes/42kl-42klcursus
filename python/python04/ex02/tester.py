# from callLimit import callLimit


# @callLimit(3)
# def f():
#     print("f()")


# @callLimit(1)
# def g():
#     print("g()")


# @callLimit(3)
# def e(a, b):
#     print(a, b)


# for i in range(5):
#     e(10, 11)

# for i in range(3):
#     f()
#     g()


from callLimit import callLimit


@callLimit(0)
def h():
    print("h()")


@callLimit(2)
def j():
    print("j()")


@callLimit(1)
def k():
    print("k()")


for i in range(2):
    h()
    j()
    k()
