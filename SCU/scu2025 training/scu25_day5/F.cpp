#include <bits/stdc++.h>
using namespace std;

const int K = 34000;
const int N = 17;
double x[N], y[N];
double d[N][N];
double dp[17][K];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    memset(dp, 127, sizeof(dp));

    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            d[i][j] = d[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        }
    }

    for(int i = 1; i <= n; i++) {
        dp[i][(1 << (i - 1))] = d[0][i]; 
    }

    for(int k = 1; k < (1 << n); k++) {
        for(int j = 1; j <= n; j++) {
            if(k & (1 << (j - 1))) {
                int pk = k - (1 << (j - 1));
                for(int i = 1; i <= n; i++) {
                    if(i == j || !((1 << (i - 1)) & pk)) continue;
                    dp[j][k] = min(dp[j][k], dp[i][pk] + d[j][i]);
                } 
            }
        }
    }
    double ans = DBL_MAX;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, dp[i][(1 << n) - 1]);
    }

    cout << fixed << setprecision(2) << ans << endl; 


    return 0;
}


