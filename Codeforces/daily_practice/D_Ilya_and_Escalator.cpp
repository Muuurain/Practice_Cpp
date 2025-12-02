// template_pre_standard

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define debug(x) (cout << "debug(" << #x << "): " << x << '\n')

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, t;
    double p;
    cin >> n >> p >> t;

    vector<vector<double> > dp(t + 5, vector<double>(n + 5));
    dp[1][1] = p;
    dp[1][0] = 1 - p;
    for(int i = 2; i <= t; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) {
                dp[i][j] = dp[i - 1][j] * (1 - p);
            }
            else if(j == n) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * p;
                break;
            }
            else {
                dp[i][j] = dp[i - 1][j] * (1 - p) + dp[i - 1][j - 1] * p;
            }
        }
    }

    double ans = 0;
    for(int i = 0; i < min((int)dp[t].size(), (int)n + 1); i++) {
        ans += i * dp[t][i];
    }
    cout << fixed << setprecision(7) << ans << '\n';

    return 0;
}