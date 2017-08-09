""" Project Euler, problem 11
Largest product in a grid
https://projecteuler.net/problem=11
"""


# Store all the inputs in a 20 by 20 matrix
mat = []

# Prompt for input
file = open('Problem11Input.txt', 'r').readlines()

# We get a 20 by 20 grid as input, so use split to store input into the array
for i in range(0, len(file)):
    row = file[i].split()
    int_row = []
    # Go through the row to remove leading zeroes
    j = 0
    for j in range(0, len(row)):
        if row[j][0] == '0':
            int_row.append(int(row[j][1]))
        else:
            int_row.append(int(row[j]))
    mat.append(int_row)

# Check the product of length-4 downwards column of numbers
def check_down(r, c):
    if r <= 16:
        product = 1
        for i in range(0, 4):
            product *= mat[r + i][c]
        return product
    return 0


# Check the product of the length-4 right row of numbers
def check_right(r, c):
    if c <= 16:
        product = 1
        for i in range(0, 4):
            product *= mat[r][c + i]
        return product
    return 0


# Check the length-4 major diagonal
def check_rdiag(r, c):
    if r <= 16 and c <= 16:
        product = 1
        for i in range(0, 4):
            product *= mat[r + i][c + i]
        return product
    return 0


# Check the length-4 minor diagonal
def check_ldiag(r, c):
    if r >= 3 and c <= 16:
        product = 1
        for i in range(0, 4):
            product *= mat[r -  i][c + i]
        return product
    return 0


# Run tests on every cell in the matrix and store the max
def run_checks():
    maxi = 0
    r = 0
    while r < 20:
        c = 0
        while c < 20:
            temp = max(check_down(r, c), check_right(r, c),
                       check_rdiag(r, c), check_ldiag(r, c))
            if temp > maxi:
                maxi = temp
            c += 1
        r += 1
    return maxi


print(run_checks())
