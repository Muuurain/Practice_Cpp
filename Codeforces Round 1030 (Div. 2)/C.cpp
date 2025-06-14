#include <bits/stdc++.h>
using namespace std;


typedef unsigned long long ll;
ll pow2[70];
ll pw(ll n) {
    ll ret = 1;
    ll a = 2;
    while(n) {
        if(n & 1) ret = (ret * a);
        a = a * a;
        n >>= 1;
    }
    return ret;
}
void solve() {
    ll n, k;
    cin >> n >> k;
    ll ret = 0;
    vector<ll> num(n);
    vector<ll> bn(70);
    ll maxdig = 0;
    for(ll i = 0; i < n; i++) {
        cin >> num[i];
        ll t = num[i];
        ret += __builtin_popcountll(t);
        ll cnt = 1;
        if(t == 0) {
            bn[0]++;
        }
        while(t) {
            if(t & 1) {
                maxdig = max(maxdig, cnt);
                break;
            }
            bn[cnt]++;            
            cnt++;
            t >>= 1;
        }
    }
    for(ll i = 1; i < 70; i++) {
            bn[i] += bn[0];
    }
    if(bn[0]) {
        maxdig = 69;
    }
    for(ll i = 1; i <= maxdig; i++) {
        ll t = 0;
        if(i == 1) t = i * bn[i];
        else {
            t = (pow2[i] - pow2[i - 1]) * bn[i];
        }
        if(t <= k) {
            ret += bn[i];
            k -= t;
        }
        else {
            ll nd = t / bn[i];
            ret += k / nd;
            break;
        }
    }
    cout << ret << endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    for(ll i = 0; i < 65; i++) {
        pow2[i] = pw(i);
    }
    while(t--) solve();
    return 0;
}