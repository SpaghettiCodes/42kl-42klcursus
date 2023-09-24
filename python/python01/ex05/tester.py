from load_image import ft_load
from pimp_image import *

import matplotlib.pyplot as plt

array = ft_load("landscape.jpg")

inverted = ft_invert(array)
red = ft_red(array)
green = ft_green(array)
blue = ft_blue(array)
grey = ft_grey(array)

print(ft_invert.__doc__)

# plt.imshow(inverted)
# plt.imshow(red)
# plt.imshow(green)
# plt.imshow(blue)
plt.imshow(grey)
plt.show()