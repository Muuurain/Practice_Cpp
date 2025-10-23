#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
ll cal(ll n, ll m) {
    ll way1 = (n - 1) * (n - 2) % MOD * (m - 2) % MOD * 2 % MOD;
    ll way2 = (n - 2) * (n - 2) % MOD * (m - 1) % MOD * 2 % MOD;
    return (way1 + way2 + (n - 1) * 2 % MOD * (m - 2) % MOD * 2 % MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    ll ret = cal(n, m) + cal(m, n);
    ret %= MOD;
    cout << ret << '\n';

    return 0;
}