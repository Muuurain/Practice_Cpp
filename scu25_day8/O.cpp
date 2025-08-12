#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
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
ll cal(int n) {
    ll ans = 1;
    for(int i = 2; i <= n; i++) {
        ans = ans * i % MOD;
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    ll ans = cal(2 * n);
    ll rev = mypow(2, MOD - 2, MOD);
    ans = ans * rev % MOD;
    cout << ans << endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}