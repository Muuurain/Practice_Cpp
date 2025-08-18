#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int K = 20 + 5;
int n, k;
int Cow[N];
vector<int> filed[N];
int dp[N][K];
void dfs1(int son, int fa) {
    dp[son][0] = Cow[son];
    for(int i = 0; i < filed[son].size(); i++) {
        if(filed[son][i] == fa) continue;
        dfs1(filed[son][i], son);
        for(int j = 1; j <= k; j++) {
            dp[son][j] += dp[filed[son][i]][j - 1];
        }
    }
}
void dfs2(int son, int fa) {
    for(int i = 0; i < filed[son].size(); i++) {
        if(filed[son][i] == fa) continue;
        for(int j = k; j >= 2; j--) {
            dp[filed[son][i]][j] -= dp[filed[son][i]][j - 2];
        }
        for(int j = k; j >= 1; j--) {
            dp[filed[son][i]][j] += dp[son][j - 1];
        }
        dfs2(filed[son][i], son);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        filed[u].push_back(v);
        filed[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        cin >> Cow[i];
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for(int i = 1; i <= n; i++) {
        int ans = 0;
        for(int j = 0; j <= k; j++) {
            ans += dp[i][j];
        }
        cout << ans << endl;
    }

    return 0;
}