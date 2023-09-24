from callLimit import callLimit
@callLimit(3)
def f():
	print ("f()")

@callLimit(1)
def g():
	print ("g()")

@callLimit(3)
def e(a,b):
	print(a,b)

for i in range(5):
	e(10, 11)

for i in range(3):
	f()
	g()
