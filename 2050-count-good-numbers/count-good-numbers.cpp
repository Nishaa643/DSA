class Solution {
public:
    long long MOD = 1e9 + 7;

    // Fast exponentiation
    long long power(long long x, long long n) {
        long long ans = 1;

        while (n > 0) {
            if (n % 2 == 1) {
                ans = (ans * x) % MOD;
            }

            x = (x * x) % MOD;
            n /= 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long evenWays = power(5, even);
        long long oddWays = power(4, odd);

        return (evenWays * oddWays) % MOD;
    }
};