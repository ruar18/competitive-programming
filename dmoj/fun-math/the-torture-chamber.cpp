#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

vector<unsigned long long> p;

// Simple sieve
void sieve(int delta) {
    bool flags[delta + 1];
    memset(flags, 0, sizeof(flags));
    // Can start from 3, we'll just skip every even number later on
    for (int i = 3; i <= delta; i += 2) {
        if (!flags[i]) {
            p.push_back(i);
            for (unsigned long long j = i * i; j <= delta; j += i)
                flags[j] = 1;
        }
    }
}

unsigned long long segsieve(unsigned long long a, unsigned long long b) {
    int delta = ceil(sqrt(b));
    unsigned long long first = 0;
    unsigned long long ans = a < 2 && b > 2? 1 : 0;
    sieve(delta);
    bool flags[delta + 1];

    // Loop through segments
    for (unsigned long long low = a; low <= b; low += delta) {
        memset(flags, 0, sizeof(flags));
        unsigned long long high = min(low + delta - 1, b);
        // Sieve this segment using the primes
        for (int i = 0; i < p.size(); i++) {
            // First num in segment to be sieved by this prime
            first = floor(low / p[i]) * p[i];
            if (first < low)
                first += p[i];
            // Sieve
            for (unsigned long long j = first; j <= high; j += p[i]) {
                // "Normalize" the sieving into range [0, delta]
                if (j != p[i])
                    flags[j - low] = 1;
            }
            if (p[i] >= low && ((high != b && p[i] <= high) || (high == b && p[i] < high)))
                flags[p[i] - low] = 0;
        }
        // Count number of primes, starting from odd num in jumps of 2
        for (unsigned long long i = max((unsigned long long) 3, low % 2 == 0 ? low + 1 : low); (high < b && i <= high)|| (high == b && i < high) ; i += 2) {
            ans += !flags[i - low];
        }
    }
    return ans;
}

int main() {
    unsigned long long a = 0, b = 0;
    scanf("%lld%lld", &a, &b);
    printf("%lld\n", segsieve(a, b));
    return 0;
}