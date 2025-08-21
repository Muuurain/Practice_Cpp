#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    ll n;
    cin >> n;
    vector<ll> ans;

    ll p = 10;
    for (int k = 1; k <= 18; k++) {
        ll d = p + 1;
        if (n % d == 0) {
            ll x = n / d;
            ans.push_back(x);
        }
        if (p > 1e17) break;
        p *= 10;
    }

    if (ans.empty()) {
        cout << 0 << "\n";
    } else {
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (ll x : ans) cout << x << " ";
        cout << "\n";
    }
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