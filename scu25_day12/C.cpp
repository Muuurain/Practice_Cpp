#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
struct cmp{
    bool operator()(pair<ll, ll> a, pair<ll, ll> b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<ll, ll> > > path(n + 1);
    for(int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        path[u].push_back({v, w});
    }
    vector<ll> vis(n + 1), ans(n + 1, LLONG_MAX);
    
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, cmp> dis;
    dis.push({s, 0});
    while(!dis.empty()) {
        auto [v, w] = dis.top();
        dis.pop();
        if(vis[v]) continue;
        
        ans[v] = w;
        vis[v] = 1;
        for(auto [vi, wi] : path[v]) {
            if(ans[vi] > ans[v] + wi) {
                ans[vi] = ans[v] + wi;
                dis.push({vi, ans[vi]});
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}