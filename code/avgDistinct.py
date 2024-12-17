def average(array):
    mySet = set(array)
    s = 0
    for elem in mySet:
        s += elem
    return round( s / len(mySet), 3 )

if __name__ == '__main__':
    input_str = "10 161 182 161 154 176 170 167 171 170 174"
    numbers = list(map(int, input_str.split()))
    N = numbers[0]
    array = numbers[1:N+1]
    result = average(array)
    print(result)