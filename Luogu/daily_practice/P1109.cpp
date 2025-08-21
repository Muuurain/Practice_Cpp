#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, l, r;
    cin >> n;
    ll ns = 0, nb = 0;
    ll hb = 0, hs = 0;
    vector<ll> a(n);
    for(ll &i : a) cin >> i;
    cin >> l >> r;
    for(ll t : a) {
        if(t >= l && t <= r) {
            hb += t - l;
            hs += r - t;
        }
        else if(t < l) {
            nb += l - t;
            hs += r - t;
        }
        else {
            ns += t - r;
            hb += t - l;
        }
    }
    if(nb > hb || ns > hs) cout << -1 << endl;
    else cout << max(ns, nb) << endl;

    return 0;
}