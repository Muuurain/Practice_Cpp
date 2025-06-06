#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const long long MOD = 998244353;

bool is_square_free(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % (i * i) == 0) return false;
    }
    return true;
}

vector<int> factorize(int x) {
    vector<int> res;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            res.push_back(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) res.push_back(x);
    return res;
}

long long compute_g(int m, const vector<long long>& f, int n) {
    if (!is_square_free(m)) return 0;
    long long res = 0;
    for (int x = m; x <= n; x += m) {
        if (is_square_free(x)) {
            res = (res + f[x]) % MOD;
        }
    }
    return res;
}

long long inclusion_exclusion(int d, const vector<long long>& f, int n) {
    vector<int> factors = factorize(d);
    int k = factors.size();
    long long res = 0;
    for (int mask = 0; mask < (1 << k); ++mask) {
        int cnt = __builtin_popcount(mask);
        long long m = 1;
        for (int i = 0; i < k; ++i) {
            if (mask & (1 << i)) m *= factors[i];
        }
        long long term = compute_g(m, f, n);
        res = (res + (cnt % 2 ? -term : term) + MOD) % MOD;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> f(n + 1, 0);
        for (int x = 1; x <= n; ++x) {
            if (is_square_free(x)) {
                vector<int> factors = factorize(x);
                int mu = (factors.size() % 2 == 0) ? 1 : -1;
                f[x] = (mu * x) % MOD;
                if (f[x] < 0) f[x] += MOD;
            }
        }
        long long ans = 0;
        for (int d = 1; d <= n; ++d) {
            if (!is_square_free(d)) continue;
            long long fd = f[d];
            long long sd = inclusion_exclusion(d, f, n);
            ans = (ans + fd * sd) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
