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

const ll MOD = 998244353;
struct edge {
    int u, v;
    ll sum;
    edge() {};
    edge(int u, int v, ll s) : u(u), v(v), sum(s) {};
};
bool cmp(const edge& a, const edge& b) {
    return a.sum > b.sum;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 5);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<edge> e(m);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        ll s;
        s = a[u] + a[v];
        e[i] = edge(u, v, a[u] + a[v]);
    }
    sort(e.begin(), e.end(), cmp);
    ll ans = 0;
    vector<map<ll, ll> > dp(n + 5);
    for(auto eg : e) {
        int u = eg.u;
        int v = eg.v;
        ll sum = eg.sum;
        ll curdp = dp[v][sum];
        curdp++;
        curdp %= MOD;
        dp[u][a[v]] += curdp;
        dp[u][a[v]] %= MOD;
        ans += curdp;
        ans %= MOD;
    }

    cout << ans << '\n';
    return;
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