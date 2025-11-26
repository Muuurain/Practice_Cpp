#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<ll> num(n);
    for(auto& i : num) cin >> i;
    ll maxo = INT_MIN, maxe = 0;
    for(int i = 0; i < n; i++) {
        ll t = maxo;
        maxo = max(max(maxe + num[i], maxo), num[i]);
        maxe = max(t - num[i], maxe);
    }
    cout << max(max(maxo, maxe), 0LL) << '\n';
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