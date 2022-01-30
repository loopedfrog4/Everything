import numpy as np

# a = np.array([[1,2,3,4,5,6,7,8,9], [9,8,7,6,5,4,3,2,1]],dtype='int8')
# a[1, 1:8:2] = [5,5,5,5]

# print(a[1, 1:8:2])
# print(a.shape)

# b = np.array([[[1,2],[3,4]], [[5,6],[7,8]]])
# [[[1 2]
#   [3 4]]

#  [[5 6]
#   [7 8]]]
# b[1,:,0] = [9,9]
# print(b)


# c = np.zeros((2,3))
# print(c)


# d = np.ones((4,2,3), dtype="int8")
# print(d)

# e = np.full(a.shape, 101, dtype="int32")
# print(e)

# f = np.random.rand(2,4)
# print(f)

# g = np.random.randint(7, size=(3,3))
# print(g)

# h = np.array([[1,2]])
# r1 = np.repeat(h, 4, axis=1)
# print(r1)

def challenge1Array():
    challenge = np.ones((5,5))
    challenge[1:4,1:4] = np.zeros(challenge[1:4,1:4].shape)
    challenge[2,2] = 9
    return challenge
# print(challenge1Array())

a = np.array([1,2,3])
b = a.copy()
b[0] = 100
print(a)
print(b)




































































































