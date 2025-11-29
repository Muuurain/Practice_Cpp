#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for(auto& i : a) cin >> i;
    vector<ll> pre(n), bac(n);
    pre[0] = a[0];
    bac[n - 1] = a[n - 1];
    for(int i = 1; i < n; i++) pre[i] = pre[i - 1] | a[i];
    for(int i = n - 2; ~i; i--) bac[i] = bac[i + 1] | a[i];
    ll ans = 0;
    ll magic = pow(x, k);
    for(int i = 0; i < n; i++) {
        ans = max(ans, (a[i] * magic) | (i == 0 ? 0 : pre[i - 1]) | (i == n - 1 ? 0 : bac[i + 1]));
    }
    cout << ans << '\n';

    return 0;
}