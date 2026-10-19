#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Dot {
    ll x, y;
};

struct State {
    int u; // 当前所在的路由器编号
    int c; // 走到当前节点已使用的备选路由器数量
    int d; // 走到当前节点已经过的中转路由器数量
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    ll r;
    cin >> n >> m >> k >> r;

    int sumd = n + m;
    vector<Dot> dots(sumd + 1);
    for (int i = 1; i <= sumd; i++) {
        cin >> dots[i].x >> dots[i].y;
    }

    ll r2 = r * r;
    auto con = [&](int u, int v) {
        ll dx = dots[u].x - dots[v].x;
        ll dy = dots[u].y - dots[v].y;
        return dx * dx + dy * dy <= r2;
    };

    vector<int> min_c(sumd + 1, k + 1);
    queue<State> q;

    min_c[1] = 0;
    q.push({1, 0, 0});

    while (!q.empty()) {
        auto [u, c, d] = q.front();
        q.pop();

        // 注意：绝不能在这里写 if (c > min_c[u]) continue;
        // 因为 min_c[u] 可能已经被第 d+1 层的状态提前改小了，但当前出队的是第 d 层的状态！

        for (int i = 2; i <= sumd; i++) {
            int nc = c + (i > n);

            if (nc < min_c[i] && con(u, i)) {
                if (i == 2) {
                    cout << d << '\n';
                    return 0;
                }
                min_c[i] = nc;
                q.push({i, nc, d + 1});
            }
        }
    }

    return 0;
}