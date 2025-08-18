#include <bits/stdc++.h>
using namespace std;

int v[110], t[1010];
int dp[110][1010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, M;
    cin >> T >> M;
    for(int i = 1; i <= M; i++) {
        cin >> t[i] >> v[i];
    }

    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= T; j++) {
            if(t[i] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + v[i]);
            }
        }
    }

    cout << dp[M][T] << endl;

    return 0;
}