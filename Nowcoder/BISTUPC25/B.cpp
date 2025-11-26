#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD =  998244353;
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
    int n;
    cin >> n;
    ll ans = mypow(2, n - 1, MOD);

    cout << ans << '\n';

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