def sieve(n):
    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False

    for i in range(2, (n + 1)):
        if sieve[i]:
            for j in range(i*i, (n + 1), i):
                sieve[j] = False

    return sieve



def count_primes(arr, start, finish):
    numPrimes = 0
    if start % 2 == 0:
        start += 1
    if start <= 2:
        numPrimes += 1
    for elem in range(start, finish, 2):
        if arr[elem]:
            numPrimes += 1

    return numPrimes


primes = sieve(1000000)
n = int(input())
for i in range(0, n):
    a, b = map(int, input().split())
    print(count_primes(primes, a, b))