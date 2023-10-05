def callLimit(limit: int):
    count = 0

    def callLimiter(function):
        def limit_function(*args: any, **kwds: any):
            nonlocal count
            count += 1
            if count > limit:
                print(f"{function} call too many times")
            else:
                function(*args, **kwds)
        return limit_function
    return callLimiter


if __name__ == "__main__":
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
