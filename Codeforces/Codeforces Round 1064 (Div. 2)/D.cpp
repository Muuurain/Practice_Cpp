#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;
void solve() {
    int n;
    cin >> n;
    vector<ll> num(n), cnt(n + 5);
    ll maxcnt = 0;
    for(auto& i : num) {
        cin >> i;
        maxcnt = max(maxcnt, ++cnt[i]);
    }
    ll ans = 0;
    vector<ll> dp(n + 5);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(cnt[i]) {
            for(int j = n; j >= cnt[i]; j--) {
                (dp[j] += dp[j - cnt[i]] * cnt[i]) %= MOD;
            }
        }
    }
    for(int i = maxcnt; i <= n; i++) {
        (ans += dp[i]) %= MOD;
    }
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