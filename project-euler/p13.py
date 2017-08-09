file = open('Problem13Data.txt', 'r').readlines()

nums = []

# Input into a 2D matrix
for i in range(0, len(file)):
    row = file[i]
    newRow = []
    for j in range(0, len(row)):
        if row[j] != '\n':
            newRow.append(int(row[j]))
    nums.append(newRow)

# Store the digits of the sum
digits = []


def add():
    sum = 0
    import math
    for i in reversed(range(0, 50)):
        sum = math.floor(sum / 10)
        for j in range(0, 100):
            sum += nums[j][i]
        if i == 0:
            digits.append(sum)
        else:
            digits.append(sum % 10)


add()
print(len(digits))
for i in reversed(range(40,50)):
    print(digits[i])

