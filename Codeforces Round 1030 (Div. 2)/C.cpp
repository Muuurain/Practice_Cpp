#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
ll pow2[40];
ll pw(int n) {
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
        ll cnt = 0;
        if(t == 0) {
            bn[0]++;
        }
        while(t) {
            if(t & 1) {
                if(cnt) {
                    bn[cnt]++;
                    maxdig = max(maxdig, cnt);
                    break;
                }
            }
            cnt++;
            t >>= 1;
        }
    }
    for(int i = 1; i < 70; i++) {
            bn[i] += bn[0];
    }
    for(int i = 1; i <= maxdig; i++) {
        ll t = 0;
        if(i == 1) t = i * bn[i];
        else {
            t = (pow2[i] - pow2[i - 1]) * bn[i];
        }
        if(t <= k) {
            ret += i * bn[i];
            if(i == 1) k -= t;
            else {
                k -= t;
            }
        }
        else {
            ll nd = pow2[i] - pow2[i - 1];
            ret += k / nd;
            break;
        }
    }
    cout << ret << endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < 40; i++) {
        pow2[i] = pw(i);
    }
    while(t--) solve();
    return 0;
}