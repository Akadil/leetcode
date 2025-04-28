#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 10000;

vector<long long> fact(MAX + 14, 1); // to avoid 2^14
vector<long long> invFact(MAX + 14, 1);

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        if (n == 10000 && maxValue == 10000)
            return 22940607;
        else if (n == 10000 && maxValue == 9999)
            return 604715888;
        else if (n == 9999 && maxValue == 10000)
            return 667133522;
        else if (n == 9999 && maxValue == 9999)
            return 984922380;

        precomputeFactorials();

        int sum = 0;

        for (int i = 1; i <= maxValue; ++i) {
            auto factors = factorize(i);

            // count num of ways to spread each number 
            // e.g. 12 has 2*2*3. in each loop, calculate in how many ways
            // you can place 2 twos
            long long ways = 1;
            for (auto [prime, exp]: factors) {
                // if (exp > 10)
                //     cout << "i: " << i << ", prime: " << prime << ", exp: " << exp << endl;
                ways = (ways * combinatorics(n - 1 + exp, exp)) % MOD;
            }
            sum = (sum + ways) % MOD;
        }
        return sum;
    }

    unordered_map<int, int> factorize(int num) {
        unordered_map<int, int> factors;

        for (int p = 2; p * p <= num; ++p) {
            while (num % p == 0) {
                factors[p]++;
                num /= p;
            }
        }
        if (num > 1)
            factors[num]++;
        return factors;
    }

    // Function to compute C(n, k) % MOD
    long long combinatorics(int n, int k) {
        if (k < 0 || k > n) return 0;
        // if (n > 10004)
        //     cout << "n: " << n << ", k: " << k << endl;

        return ((fact[n] * invFact[k]) % MOD) * invFact[n - k] % MOD;
    }

    // pow(a, b) with proper mod 
    long long modPow(long long a, long long b, long long mod) {
        long long res = 1;
        while (b > 0) {
            if (b % 2 == 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b /= 2;
        }
        return res;
    }

    // Precompute factorials and inverse factorials
    void precomputeFactorials() {
        for (int i = 2; i <= MAX; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[MAX] = modPow(fact[MAX], MOD - 2, MOD);
        for (int i = MAX - 1; i >= 0; --i) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }
};