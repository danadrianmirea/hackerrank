import numpy

# Input the shape as a single line of space-separated integers
shape = tuple(map(int, input().split()))

# Create and print the zeros array
zeros_array = numpy.zeros(shape, dtype=int)
print(zeros_array)

# Create and print the ones array
ones_array = numpy.ones(shape, dtype=int)
print(ones_array)
