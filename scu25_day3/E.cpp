#include <bits/stdc++.h>
using namespace std;

const int n = 110;
int prefix[2 * n];
int a[n];
int dp1[2 * n][2 * n], dp2[2 * n][2 * n];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    a[0] = a[N];

    for(int i = 1; i < 2 * N; i++) {
        prefix[i] = prefix[i - 1] + a[i % N];
    }
    for(int i = 0; i < 2 * n; i++) {
        for(int j = 0; j < 2 * n; j++) {
            dp1[i][j] = INT_MAX;
            dp2[i][j] = INT_MIN;
        }
    }
    for(int i = 0; i < 2 * N; i++) {
        dp1[i][i] = 0;
        dp2[i][i] = 0;
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 1; (j + i - 1) <= 2 * N; j++) {
            for(int k = j + 1; k <= j + i - 1; k++) {
                dp1[j][j + i - 1] = min(dp1[j][j + i - 1], dp1[j][k - 1] + dp1[k][j + i - 1] + prefix[j + i - 1] - prefix[j - 1]);
                dp2[j][j + i - 1] = max(dp2[j][j + i - 1], dp2[j][k - 1] + dp2[k][j + i - 1] + prefix[j + i - 1] - prefix[j - 1]);
            }
        }
    }

    int ans1 = INT_MAX, ans2 = INT_MIN;
    for(int i = 1; (i + N) <= 2 * N; i++) {
        ans1 = min(ans1, dp1[i][i + N - 1]);
        ans2 = max(ans2, dp2[i][i + N - 1]);
    }

    cout << ans1 << endl;
    cout << ans2 << endl;
    

    return 0;
}