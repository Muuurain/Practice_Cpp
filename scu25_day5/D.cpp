#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> tree[N];
int ret[N];
int dfs(int node, int fa, int root) {
    vector<int> sontime;
    for(int i = 0; i < tree[node].size(); i++) {
        int son = tree[node][i];
        if(son != fa) sontime.push_back(dfs(son, node, root));

    }
    sort(sontime.rbegin(), sontime.rend());
    int maxtime = 0;
    for(int i = 0; i < sontime.size(); i++) {
        maxtime = max(sontime[i] + i + 1, maxtime);
    }
    return maxtime;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >>n;
    for(int i = 2; i <= n; i++) {
        int pa;
        cin >> pa;
        tree[i].push_back(pa);
        tree[pa].push_back(i);
    }
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++) {
        ret[i] = dfs(i, 0, i);
        ans = min(ans, ret[i]);
    }

    cout << (ans + 1) << endl;
    for(int i = 1; i <= n; i++) {
        if(ans == ret[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}