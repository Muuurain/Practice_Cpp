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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, p;
    cin >> n >> p;
    for(int i = 1; i <= n; i++) {
        ll ans = mypow(i, p - 2, p);
        cout << ans << endl;
    }

    return 0;
}