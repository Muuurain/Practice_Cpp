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

int R, C;
vector<vector<char> > mp;
vector<vector<bool> > vis1, vis2;

int dx[4] = {0, 0, -1, 1}; // 上下左右
int dy[4] = {-1, 1, 0, 0};
#define mpaim (mp[i][j])

void DFS1(int i, int j) {
    if(mpaim == '#' || mpaim == 0 || vis1[i][j] == true) return;
    vis1[i][j] = true;
    if(mpaim == 'S' || mpaim == 'T' || mpaim == '+') {
        for(int k = 0; k < 4; k++) {
            DFS1(i + dy[k], j + dx[k]);
        }
    }
    else if(mpaim == '-') {
        DFS1(i + dy[2], j + dx[2]);
        DFS1(i + dy[3], j + dx[3]);
    }
    else if(mpaim == '|') {
        DFS1(i + dy[0], j + dx[0]);
        DFS1(i + dy[1], j + dx[1]);
    }
    else {
        DFS1(i + dy[1], j + dx[1]);
    }
}

bool check2(int i, int j, int dir) {
    if(mpaim == '#' || mpaim == 0) return false;
    if(mpaim == '+' || mpaim == 'S' || mpaim == 'T') return true;
    if(mpaim == '-' && (dir == 2 || dir == 3)) return true;
    if(mpaim == '|' && (dir == 0 || dir == 1)) return true;
    if(mpaim == '.' && dir == 0) return true;
    return false;
}
void DFS2(int i, int j) {
    if(vis2[i][j]) return;
    vis2[i][j] = true;
    for(int k = 0; k < 4; k++) {
        if(check2(i + dy[k], j + dx[k], k)) {
            DFS2(i + dy[k], j + dx[k]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;
    mp.resize(R + 5, vector<char>(C + 5));
    vis1.resize(R + 5, vector<bool>(C + 5));
    vis2.resize(R + 5, vector<bool>(C + 5));

    int aimx = 0, aimy = 0;
    int stx = 0, sty = 0;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 'S') {
                stx = j;
                sty = i;
            }
            else if(mp[i][j] == 'T') {
                aimx = j;
                aimy = i;
            }
        }
    }
    DFS1(sty, stx); // 从起点开始遍历
    DFS2(aimy, aimx); // 从终点开始遍历
    int ans = 0;

    if(vis1[aimy][aimx]) {
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++) {
                if(vis1[i][j] && !vis2[i][j]) ans++;
            }
        }
        cout << ans << '\n';
    }
    else cout << "I'm stuck!" << '\n';

    return 0;
}