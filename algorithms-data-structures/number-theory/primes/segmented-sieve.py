# An implementation of the segsieve algorithm
# Finds the number of primes in range [a, b] in O(n log log b)
# time and O(sqrt(b)) space

from math import *
p = []

# Generate list of important primes
def sieve(delta):
    flags = [None] * (delta+1)
    for i in range(3, delta+1, 2):
        if not flags[i]:
            p.append(i)
            for j in range(i*i, delta+1, i):
                flags[i] = 1


def segsieve(a, b):
    delta = ceil(sqrt(b))
    # Initialize the number of primes
    # If the range includes 2, add 1, since we're skipping 2 with the sieve
    ans = 1 if (a <= 2 and b >= 2) else 0
    # Generate primes
    sieve(delta)
    # Flags for each segment
    flags = [None] * (delta+1)

    # Loop through segments
    for low in range(a, b+1, delta):
        flags = [0] * (delta+1)
        # Compute the endpoint of this segment: either a normal endpoint, or the end  of the range
        high = min(low + delta - 1, b)

        # Loop through the primes to segment the sieve
        for prime in p:
            # First number to be sieved by this prime
            first = floor(low // prime) * prime
            if first < low:
                first += prime

            # Sieve
            for i in range(first, high+1, prime):
                # If j is not the prime itself
                if i != prime:
                    # Normalize the sieve into range [0, delta]
                    flags[i - low] = 1


        # Count the number of primes in the segment after sieving
        # Start from an odd number, in jumps of 2
        for i in range(max(3, low+1 if (low % 2 == 0) else low), high+1, 2):
            if flags[i - low] == 0:
                ans += 1
                if ans % 10000 == 0:
                    print(ans)

    return ans


a, b = map(int, input().split())
print("Number of primes in range: %d" % segsieve(a, b))
