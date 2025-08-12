#include <bits/stdc++.h>
using namespace std;

const int maxN = (1 << 20) + 10;
int dp[maxN];
int st[110];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    memset(dp, 0x3F3F3F3F, sizeof(dp));

    for(int i = 1; i <= N; i++) {
        int t = 0;
        for(int j = 1; j <= K; j++) {
            int temp;
            cin >> temp;
            t |= 1 << (temp - 1);
        }
        dp[t] = 1;
        st[i] = t;
    }

    for(int k = 1; k < (1 << M); k++) {
        for(int i = 1; i <= N; i++) {
            dp[k | st[i]] = min(dp[k | st[i]], dp[k] + 1);
        }
    }

    if(dp[(1 << M) - 1] > 110) cout << -1;
    else cout << dp[(1 << M) - 1];
    return 0;
}