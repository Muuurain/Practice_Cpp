#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct dot {
    ll x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    ll r;
    cin >> n >> m >> k >> r;
    int sumd = n + m;
    vector<dot> dots(sumd + 1);

    for (int i = 1; i <= sumd; i++) {
        cin >> dots[i].x >> dots[i].y;
    }

    auto con = [&](int u, int v) {
        ll dx = dots[u].x - dots[v].x;
        ll dy = dots[u].y - dots[v].y;
        return dx * dx + dy * dy <= r * r;
    };

    vector<vector<int>> step(sumd + 1, vector<int>(k + 1, -1));
    queue<pair<int, int>> q;

    step[1][0] = 0;
    q.push({1, 0});

    while (!q.empty()) {
        auto [u, c] = q.front();
        q.pop();

        for (int i = 2; i <= sumd; i++) {
            int nc = c + (i > n); // i > n 时自动 +1，否则 +0
            if (nc > k || step[i][nc] != -1) continue;

            if (con(u, i)) {
                if (i == 2) {
                    cout << step[u][c] << '\n';
                    return 0;
                }
                step[i][nc] = step[u][c] + 1;
                q.push({i, nc});
            }
        }
    }

    return 0;
}