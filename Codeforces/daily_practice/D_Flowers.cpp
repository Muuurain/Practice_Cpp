// template_pre_cf

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define debug(x) (cout << "debug(" << #x << "): " << x << '\n')
const ll MOD = 1e9 + 7;
const ll MAXN = 1e5 + 10;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    ll k;
    cin >> t;
    cin >> k;
    vector<ll> dp(MAXN);
    vector<ll> pre(MAXN);
    dp[0] = 1;
    pre[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        if(i >= k) {
            dp[i] = dp[i - 1] + dp[i - k];
            dp[i] %= MOD;
        }
        else {
            dp[i] = dp[i - 1];
        }
        pre[i] = pre[i - 1] + dp[i];
        pre[i] %= MOD;
    }
    while(t--) {
        ll a, b;
        cin >> a >> b;
        cout << (ll)(MOD + pre[b] - pre[a - 1]) % MOD << '\n';
    }

    return 0;
}