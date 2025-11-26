#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> dp(n + 5);
    dp[0] = 1;
    dp[1] = 4;
    for(int i = 2; i <= n; i++) {
        dp[i] = 3 * dp[i - 1] + 1 - dp[i - 2] + MOD;
        dp[i] %= MOD;
    }
    
    cout << dp[n] << endl;

    return 0;
}