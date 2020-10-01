from cs50 import get_int

while True:
    height = get_int("Enter the pyramid height: ")
    if height <= 8 and height > 0:  # input must be smaller than 8 and be positive
        break

for i in range(height, 0, -1):  # where the magic happens
    print(" " * (i - 1), end="")
    print("#" * (height + 1 - i), end="")
    print("  ", end="")
    print("#" * (height + 1 - i))