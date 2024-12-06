def is_leap(year):
    leap = False
    # Check divisibility by 4
    if year % 4 == 0:
        # Check divisibility by 100
        if year % 100 == 0:
            # Check divisibility by 400
            if year % 400 == 0:
                leap = True
        else:
            leap = True
    return leap

# Input year
year = int(input("Enter a year: "))
print(is_leap(year))
