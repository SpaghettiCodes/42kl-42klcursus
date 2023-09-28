import numpy as np

# test = \
# [
# 	[[1,2,3],[4,5,6],[7,8,9]],
# 	[[10,11,12],[13,14,15],[16,17,18]]
# ]

test =\
    [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]

test2 = np.array(test)
for row in test2:
    print(row[1])

# test3 = np.array([test2[::, x] for x in range(dimen[1])])
# print(test3)
