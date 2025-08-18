#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(pair<int, double> a, pair<int, double> b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int A, B;
    
    vector<vector<pair<int, int> > > path(n + 1);
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        path[x].push_back({y, z});
        path[y].push_back({x, z});
    }
    cin >> A >> B;
    
    vector<double> ans(n + 1, DBL_MAX);
    priority_queue<pair<int, double>, vector<pair<int, double> >, cmp> dis;
    vector<bool> vis(n + 1);
    dis.push({A, 100.0});
    while(!dis.empty()) {
        auto [v, w] = dis.top();
        dis.pop();
        if(vis[v]) continue;
        ans[v] = w;
        vis[v] = true;

        for(auto [vi, wi] : path[v]) {
            if(ans[vi] > ans[v] / (0.01 * (100 - wi))) {
                ans[vi] = ans[v] / (0.01 * (100 - wi));
                dis.push({vi, ans[vi]});
            }
        }
    }

    cout << fixed << setprecision(8) << ans[B] << endl;
    

    return 0;
}