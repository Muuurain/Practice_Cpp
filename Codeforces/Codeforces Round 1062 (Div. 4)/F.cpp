#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void dfs(int p, int s, vector<int>& ts, vector<vector<int> >& tree) {
    for(int i = 0; i < tree[s].size(); i++) {
        if(tree[s][i] != p) {
            dfs(s, tree[s][i], ts, tree);
            ts[s] += ts[tree[s][i]];
        }
    } 
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int> > tree(n + 10);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int> ts(n + 10, 1);
    dfs(0, 1, ts, tree);
    ll ans = n;
    for(int i = 1; i <= n; i++) {
        if(ts[i] >= k) ans += n - ts[i];
        if(n - ts[i] >= k) ans += ts[i];
    }


    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
