#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<char>> mp;
vector<vector<int>> vis1, vis2;

const int di[4] = {-1, 1, 0, 0}; // 0:上, 1:下, 2:左, 3:右
const int dj[4] = {0, 0, -1, 1};

// 通用辅助函数：判断站在 (i, j) 能否向方向 dir (0~3) 迈出一步
bool can_move(int i, int j, int dir) {
    char c = mp[i][j];
    if (c == '#' || c == 0) return false;
    if (c == '+' || c == 'S' || c == 'T') return true;
    if (c == '-' && (dir == 2 || dir == 3)) return true;
    if (c == '|' && (dir == 0 || dir == 1)) return true;
    if (c == '.' && dir == 1) return true; // '.' 只能向下(dir=1)走
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    mp.resize(R + 5, vector<char>(C + 5));
    vis1.resize(R + 5, vector<int>(C + 5));
    vis2.resize(R + 5, vector<int>(C + 5));

    int si = 0, sj = 0, ti = 0, tj = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'S') si = i, sj = j;
            else if (mp[i][j] == 'T') ti = i, tj = j;
        }
    }

    // 1. 正向 BFS：入队即标记 vis1 = 1
    queue<pair<int, int>> q1;
    q1.push({si, sj});
    vis1[si][sj] = 1;
    while (!q1.empty()) {
        auto [i, j] = q1.front();
        q1.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (can_move(i, j, k) && !vis1[ni][nj] && mp[ni][nj] != '#' && mp[ni][nj] != 0) {
                vis1[ni][nj] = 1; // 关键：入队同时立刻标记！
                q1.push({ni, nj});
            }
        }
    }

    // 提前判停：如果起点根本到不了终点，直接退出
    if (!vis1[ti][tj]) {
        cout << "I'm stuck!\n";
        return 0;
    }

    // 2. 反向 BFS：入队即标记 vis2 = 1
    queue<pair<int, int>> q2;
    q2.push({ti, tj});
    vis2[ti][tj] = 1;
    while (!q2.empty()) {
        auto [i, j] = q2.front();
        q2.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            // k ^ 1 代表相反方向（0<->1 上下互换，2<->3 左右互换）
            if (!vis2[ni][nj] && can_move(ni, nj, k ^ 1)) {
                vis2[ni][nj] = 1; // 关键：入队同时立刻标记！
                q2.push({ni, nj});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (vis1[i][j] && !vis2[i][j]) ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}