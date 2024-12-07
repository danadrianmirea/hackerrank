if __name__ == '__main__':
    # Example array containing the input values
    input_array = [5, 2, 3, 6, 6, 5]  # Replace with your desired values
    input_array = [4, 57, 57, -57, 57]
    input_aray = [10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6]

    # Extract n as the first element of the array
    n = input_array[0]
    # Extract the remaining elements as the "arr" values
    arr = map(int, input_array[1:])

    prevmaxx = -100
    maxx = -100

    for num in arr:
        if maxx is -100 or num > maxx:
            prevmaxx = maxx
            maxx = num
        elif num is not maxx and ( prevmaxx is -100 or num > prevmaxx ):
            prevmaxx = num
            
    print(prevmaxx)