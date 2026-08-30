class Solution {
public:
 long long LCM(long long a, long long b, long long limit) {
        long long g = __gcd(a, b);
        a = a / g;
        if (a > limit / b)
            return limit + 1;
        return a * b;
    }
    long long countValid(long long x, vector<int>& coins) {
        int n = coins.size();
        long long ans = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            long long lcm = 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    lcm = LCM(lcm, coins[i], x);
                    if (lcm > x)
                        break;
                }
            }
            if (lcm > x)
                continue;
            long long contribution = x / lcm;
            if (__builtin_popcount(mask) % 2 == 1)
                ans += contribution;
            else
                ans -= contribution;
        }
        return ans;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int minCoin = *min_element(coins.begin(), coins.end());
        long long low = 1;
        long long high = 1LL * minCoin * k;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long cnt = countValid(mid, coins);
            if (cnt >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};