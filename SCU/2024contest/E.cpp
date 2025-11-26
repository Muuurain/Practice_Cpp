#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n;
    cin >> n;
    vector<ll> num(n), dp(n, 2);
    for(auto& i : num) cin >> i;
    dp[0] = 1;
    for(int i = 2; i < n; i++) {
        if(num[i - 1] - num[i - 2] == num[i] - num[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += dp[i];
    }

    cout << ans << endl;

    return 0;
}