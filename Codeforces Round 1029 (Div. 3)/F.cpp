#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> edge[N];
vector<int> depth;

int lca = -1;
void dfs(int n, int par, int len){
    if(edge[n].size() > 2) {
        lca = len;
    }
    for(int i = 0; i < edge[n].size(); i++) {
        if(edge[n][i] != par) {
            dfs(edge[n][i], n, len + 1);
        }
    }
    if(edge[n].size() == 1) {
        depth.push_back(len);
    }
}
ll pw(int n) {
    ll ret = 1;
    ll a = 2;
    while(n) {
        if(n & 1) ret = (ret * a) % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return ret;
}
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) edge[i].clear();
    depth.clear();
    lca = -1;
    for(int i = 1; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        edge[t1].push_back(t2);
        edge[t2].push_back(t1);
    }
    edge[1].push_back(0);
    dfs(1, 0, 1);

    if(depth.size() > 2) cout << 0 << endl;
    else if(depth.size() == 1) cout << pw(n) << endl;
    else {
        int diff = abs(depth[0] - depth[1]);
        ll ret = (pw(diff + lca) + pw(diff + lca - (diff ? 1 : 0))) % MOD;
        cout << ret << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;   
}