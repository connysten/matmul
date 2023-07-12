import numpy as np
import time

# Matrix multiplication function
def matrix_multiplication(a, b):
    return np.dot(a, b)

# Generate random matrices
size = 1000
matrix_a = np.random.rand(size, size)
matrix_b = np.random.rand(size, size)

# Perform matrix multiplication and measure time
start_time = time.time()
result = matrix_multiplication(matrix_a, matrix_b)
end_time = time.time()
execution_time = end_time - start_time

print("Python Matrix Multiplication")
print("Matrix size:", size, "x", size)
print("Execution time:", execution_time, "seconds")
