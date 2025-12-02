// template_pre_standard

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define debug(x) (cout << "debug(" << #x << "): " << x << '\n')
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> num(n);
    for(int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        if(t < 0) t = -t;
        num[i] = t;
    }
    sort(num.begin(), num.end());   

    ll ans = 0;
    for(int i = n - 1; i > 0; i--) {
        ll mxn = num[i];
        ll mi = lower_bound(num.begin(), num.end(), (double)mxn / 2) - num.begin();
        ans += max(i - mi, 0ll);
    }
    cout << ans << endl;

    return 0;
}