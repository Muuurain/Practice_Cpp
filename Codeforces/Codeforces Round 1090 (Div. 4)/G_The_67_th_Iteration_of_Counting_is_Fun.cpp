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

const ll MOD = 676767677;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> time(n + 5);
    time[0] = 3e5;
    time[n + 1] = 3e5;
    for(int i = 1; i <= n; i++) {
        cin >> time[i];
    }
    for(int i = 1; i <= n; i++) {
        if(time[i] == 0) continue;
        if(time[i] > time[i - 1] || time[i] > time[i + 1]) continue;
        cout << 0 << '\n';
        return;
    }
    vector<ll> fre(m), sum(m);

    for(int i = 1; i <= n; i++) {
        fre[time[i]]++;
    }
    sum[0] = fre[0];
    for(int i = 1; i < m; i++) {
        sum[i] = sum[i - 1] + fre[i];
    }
    ll ans = 1;
    ll t = 1;
    for(int i = 1; i <= n; i++) {
        if(time[i] == 0) continue;
        else if(time[i] == 1) ans = ans * sum[0] % MOD;
        else if(time[i] - min(time[i - 1], time[i + 1]) == 1) ans = ans * (sum[time[i] - 1]) % MOD;
        else ans = ans * (sum[time[i] - 1] - sum[time[i] - 2]) % MOD;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}