#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    ll maxa = 0;
    for(auto& i : a) {
        cin >> i;
        maxa = max(i, maxa);
    }
    sort(a.begin(), a.end());
    while(q--) {
        ll c;
        cin >> c;
        ll ans;
        if(maxa >= c) ans = 0;
        else{

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