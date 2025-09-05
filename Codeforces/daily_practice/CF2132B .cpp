#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mypow(ll a, ll b, ll p) {
    ll ans = 1;
    a %= p;
    while(b) {
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
void solve() {
    ll n;
    cin >> n;
    vector<ll> ans;
    for(int i = 1; i < 18; i++) {
        ll brd = 1 + mypow(10, i, LLONG_MAX);
        if(!(n % brd)) {
            ll x = n / brd;
            ans.push_back(x);
        }
    }
    if(ans.empty()) cout << 0 << '\n';
    else {
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(auto it : ans) {
            cout << it;
            it == ans.back() ? (cout << '\n') : (cout << " ");
        }
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