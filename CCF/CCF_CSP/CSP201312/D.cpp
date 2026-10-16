// template_pre_cf

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template <typename T>
void debug_impl(const T& val) {
    cout << val;
}
template <typename T>
void debug_impl(const vector<T>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) cout << ", ";
        debug_impl(vec[i]);
    }
    cout << "]";
}
#define debug(x) do { \
    cout << "debug(" << #x << "): "; \
    debug_impl(x); \
    cout << '\n'; \
} while(0)


const int N = 1010;
const ll MOD = 1e9 + 7;
vector<vector<ll> > dp(N, vector<ll>(6));
void solve() {
    int n;
    cin >> n;
    cout << dp[n][5] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp[1][0] = 1; // 2;

    for(int i = 2; i < N; i++) {
        dp[i][0] = (dp[i - 1][0]) % MOD; // 2
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD; // 2, 3
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][2] * 2) % MOD; // 2, 0
        dp[i][3] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] * 2) % MOD; // 2, 3, 0
        dp[i][4] = (dp[i - 1][2] + dp[i - 1][4] * 2) % MOD; // 2, 0, 1
        dp[i][5] = (dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5] * 2) % MOD; // 2, 3, 0, 1;
    }
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}

/*
若单次查询，代码改为:

dp[0] = 1;

for(int i = 2; i <= n; i++) {

    dp[5] = (dp[3] + dp[4] + dp[5] * 2) % MOD;

    dp[4] = (dp[2] + dp[4] * 2) % MOD;

    dp[3] = (dp[1] + dp[2] + dp[3] * 2) % MOD;

    dp[2] = (dp[0] + dp[2] * 2) % MOD;

    dp[1] = (dp[0] + dp[1]) % MOD;

}
最后输出dp[5]即可
*/