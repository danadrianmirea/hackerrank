if __name__ == '__main__':
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())

    # Using a list comprehension to generate the 3D grid
    coordinates = [[i, j, k] for i in range(x + 1) 
                   for j in range(y + 1) 
                   for k in range(z + 1) 
                   if i + j + k != n]

    print(coordinates)
