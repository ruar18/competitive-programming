# Collatz conjecture
# P3G problem - 3n + 1

length_of_collatz = 0


def collatz(num, length):
    while num != 1:
        if num % 2 != 0:
            num = num * 3 + 1
            length += 1
        else:
            num /= 2
            length += 1
    return length

n = int(input())
print(collatz(n, length_of_collatz))