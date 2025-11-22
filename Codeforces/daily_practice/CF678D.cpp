#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD =  1e9 + 7;

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

    ll A, B, n, x;
    cin >> A >> B >> n >> x;

    ll ans = 0;
    if(A == 1) {
        ans = (x % MOD + (n % MOD) * (B % MOD)) % MOD;
    }

    else {
        ll k = B * mypow(A - 1, MOD - 2, MOD) % MOD;
        ll a1 = ((A * x + B) % MOD + k) % MOD;
        ll qnm1 = mypow(A, n - 1, MOD);
        ans = (ll)(qnm1 * a1 - k + MOD) % MOD;
    }

    cout << ans << endl;

    return 0;
}