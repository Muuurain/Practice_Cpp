#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll k, n;
    cin >> k >> n;

    ll t = k;
    ll cnt = 1;
    while(n - t > 0) {
        n -= t;
        t *= 2;
        cnt *= 2;
    }
    ll ans = (n - 1) / cnt;
    cout << (char)('A' + ans) << endl;

    return 0;
}