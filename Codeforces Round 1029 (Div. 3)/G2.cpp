#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > mp(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mp[u - 1].push_back({v - 1, w});
        mp[v - 1].push_back({u - 1, w});
    }
        auto uwu = [&](int x) -> vector<int> {
            vector<int> ret(n, 1e9);
            vector<bool> vis(n);

            priority_queue<pair<int, int> > q;
            q.push({0, x});
            
            while(q.size()) {
                auto [m, vert] = q.top();
                q.pop();
                if(vis[vert]) continue;

                m = -m;
                vis[vert] = true;
                ret[vert] = m;
                for(auto [y, z] : mp[vert]) {
                    if(vis[y]) continue;
                    q.push({-max(m, z), y});
                }
            }
            return ret;
        };
        vector<int> dis_a = uwu(0);
        vector<int> dis_b = uwu(n - 1);
        int ans = 2e9 + 10;
        for(int i = 0; i < n; i++) {
            for(auto [x1, x2] : mp[i]) {
                ans = min(ans, max({dis_a[i], dis_b[x1], x2}) + x2);
            }
        }
        cout << ans << endl;
    }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}