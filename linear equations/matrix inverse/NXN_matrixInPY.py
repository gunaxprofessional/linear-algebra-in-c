import numpy as np

A = np.array([[2,  1,  3,  4],
              [1, 2, 1, 3],
              [3, 1, 2, 1],
              [2, 3, 1, 2]])

print(np.linalg.inv(A))

print(np.linalg.det(A))
