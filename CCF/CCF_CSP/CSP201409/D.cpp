// template_pre_standard

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template <typename T>
void debug_impl(const T& val) {
    cout << val;
}
template <typename T>
void debug_impl(const vector<T>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) cout << ", ";
        debug_impl(vec[i]);
    }
    cout << "]";
}
#define debug(x) do { \
    cout << "debug(" << #x << "): "; \
    debug_impl(x); \
    cout << '\n'; \
} while(0)

ll dx[4] = {0, 0, -1, 1}; // 上下左右
ll dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m, k, d;
    cin >> n >> m >> k >> d;

    vector<vector<ll> > cost(n + 5, vector<ll>(n + 5));
    vector<vector<ll> > num(n + 5, vector<ll>(n + 5));
    vector<vector<bool> > vis(n + 5, vector<bool>(n + 5));
    queue<pair<ll, ll> > q;

    while(m--) {
        ll x, y;
        cin >> x >> y;
        vis[x][y] = true;
        q.push({x, y});
    }
    while(k--) {
        ll  x, y, c;
        cin >> x >> y >> c;
        num[x][y] += c;
    }
    while(d--) {
        ll x, y;
        cin >> x >> y;
        vis[x][y] = true;
    }

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(ll i = 0; i < 4; i++) {
            if(x + dx[i] > 0 && x + dx[i] <= n && y + dy[i] > 0 && y + dy[i] <= n && !vis[x + dx[i]][y + dy[i]]) {
                vis[x + dx[i]][y + dy[i]] = true;
                cost[x + dx[i]][y + dy[i]] = cost[x][y] + 1;
                q.push({x + dx[i], y + dy[i]});
            }
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            ans += cost[i][j] * num[i][j];
        }
    }

    cout << ans << '\n';

    return 0;
}