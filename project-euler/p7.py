# Find the 10001st prime using the Sieve of Eratosthenes
def sieve(n):
    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False
    for i in range(2, (n + 1)):
        if sieve[i]:
            for j in range(i*i, (n + 1), i):
                sieve[j] = False

    return sieve


prime_sieve = sieve(400000);
primes = []
for idx, val in enumerate(prime_sieve):
   if val:
        primes.append(idx)
print(primes[10000])