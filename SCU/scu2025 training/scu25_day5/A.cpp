#include <bits/stdc++.h>
using namespace std;

const int N = 16010;
int b[N];
vector<int> tree[N];
int ret[N];

void dfs(int son, int fa) {
    if(!ret[son]) ret[son] = b[son];
    for(int i = 0; i < tree[son].size(); i++) {
        int sson = tree[son][i];
        if(sson != fa) {
            dfs(sson, son);
            if(ret[sson] > 0) ret[son] += ret[sson];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);

    int ans = INT_MIN;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, ret[i]);
    }

    cout << ans << endl;
    return 0;
}