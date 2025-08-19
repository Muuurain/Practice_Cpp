#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<ll> > ans(n + 5, vector<ll>(m + 5));
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(j == a[i]) ans[i][j] = ans[i - 1][j] + 1;
            else if(j > a[i]) ans[i][j] = ans[i - 1][j] + ans[i - 1][j - a[i]];
            else ans[i][j] = ans[i - 1][j];
        }
    }
    cout << ans[n][m] << endl;

    return 0;
}