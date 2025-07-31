#include <bits/stdc++.h>
using namespace std;

const int N = 6e3 + 10;
bool nhead[N];
int dp[N][2];
int hp[N];
vector<int> son[N];

void dfs(int fa) {
    dp[fa][1] = hp[fa];
    for(int i = 0; i < son[fa].size(); i++) {
        dfs(son[fa][i]);
        dp[fa][1] += dp[son[fa][i]][0];
        dp[fa][0] += max(dp[son[fa][i]][1], dp[son[fa][i]][0]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> hp[i];
    }
    for(int i = 1; i < n; i++) {
        int l, k;
        cin >> l >> k;
        son[k].push_back(l);
        nhead[l] = true;
    }
    int head = 0;
    for(int i = 1; i <= n; i++) {
        if(!nhead[i]) head = i;
    }
    dfs(head);
    int ans = max(dp[head][0], dp[head][1]);
    cout << ans << endl;

    return 0;
}