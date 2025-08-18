#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
    ll a, b, p;
    cin >> a >> b >> p;
    ll t1 = a, t2 = b;
    ll ans = 1;
    a %= p;
    while(b) {
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    cout << t1 << "^" << t2 << " mod " << p << "=" << ans << endl;

    return 0;
}