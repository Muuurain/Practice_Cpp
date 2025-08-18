#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll calfx(ll x) {
    if(x % 4 == 3) return 0;
    else if(x % 4 == 0) return 0 ^ x;
    else if(x % 4 == 1) return 1;
    else if(x % 4 == 2) return 1 ^ x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll A, B;
    cin >> A >> B;
    if(A == 0) {
        ll ans = calfx(B);
        cout << ans << endl;
        return 0;
    }
    ll fa = calfx(A - 1);
    ll fb = calfx(B);
    ll ans = fa ^ fb;
    cout << ans << endl;

    return 0;
}