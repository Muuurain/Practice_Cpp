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
vector<vector<ll> > comb(N, vector<ll>(N));
void solve() {
    int n;
    cin >> n;
    if(n < 4) {
        cout << 0 << '\n';
        return;
    }
    ll ans = 0;
    for(int i = 2; i <= n - 2; i++) {
        ans += comb[n - 1][i] * (i - 1) * (n - i - 1);
        ans %= MOD;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    comb[0][0] = comb[1][0] = comb[1][1] = 1;
    for(int i = 2; i < N; i++) {
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }
    
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}