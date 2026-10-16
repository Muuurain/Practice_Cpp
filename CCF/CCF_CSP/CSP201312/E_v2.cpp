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
queue<pair<int, int>> q1, q2;
vector<vector<int> > vis1, vis2;
#define mpaim (mp[i][j])
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

bool check2(int i, int j, int dir) {
    if(mpaim == '#' || mpaim == 0) return false;
    if(mpaim == '+' || mpaim == 'S' || mpaim == 'T') return true;
    if(mpaim == '-' && (dir == 2 || dir == 3)) return true;
    if(mpaim == '|' && (dir == 0 || dir == 1)) return true;
    if(mpaim == '.' && dir == 0) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;
    mp.resize(R + 5, vector<char>(C + 5));
    vis1.resize(R + 5, vector<int>(C + 5));
    vis2.resize(R + 5, vector<int>(C + 5));
    int si = 0, sj = 0;
    int ti = 0, tj = 0;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> mp[i][j];
            if(mpaim == 'S') {
                si = i;
                sj = j;
            }
            else if(mpaim == 'T') {
                ti = i;
                tj = j;
            }
        }
    }
    q1.push({si, sj});
    while(!q1.empty()) {
        auto temp = q1.front();
        q1.pop();
        int i = temp.first;
        int j = temp.second;
        vis1[i][j] = 1;
        if(mpaim == '+' || mpaim == 'S' || mpaim == 'T') {
            for(int k = 0; k < 4; k++) {
                if(!vis1[i + di[k]][j + dj[k]] && (mp[i + di[k]][j + dj[k]] != 0 && mp[i + di[k]][j + dj[k]] != '#')) q1.push({i + di[k], j + dj[k]});
            }
        }
        else if(mpaim == '-') {
            if(!vis1[i + di[2]][j + dj[2]] && (mp[i + di[2]][j + dj[2]] != 0 && mp[i + di[2]][j + dj[2]] != '#')) q1.push({i + di[2], j + dj[2]});
            if(!vis1[i + di[3]][j + dj[3]] && (mp[i + di[3]][j + dj[3]] != 0 && mp[i + di[3]][j + dj[3]] != '#')) q1.push({i + di[3], j + dj[3]});
        }
        else if(mpaim == '|') {
            if(!vis1[i + di[0]][j + dj[0]] && (mp[i + di[0]][j + dj[0]] != 0 && mp[i + di[0]][j + dj[0]] != '#')) q1.push({i + di[0], j + dj[0]});
            if(!vis1[i + di[1]][j + dj[1]] && (mp[i + di[1]][j + dj[1]] != 0 && mp[i + di[1]][j + dj[1]] != '#')) q1.push({i + di[1], j + dj[1]});
        }
        else {
            if(!vis1[i + di[1]][j + dj[1]] && (mp[i + di[1]][j + dj[1]] != 0 && mp[i + di[1]][j + dj[1]] != '#')) q1.push({i + di[1], j + dj[1]});
        }
    }
    q2.push({ti, tj});
    while(!q2.empty()) {
        auto temp = q2.front();
        q2.pop();
        int i = temp.first;
        int j = temp.second;
        vis2[i][j] = 1;
        for(int k = 0; k < 4; k++) {
            if(check2(i + di[k], j + dj[k], k) && !vis2[i + di[k]][j + dj[k]]) q2.push({i + di[k], j + dj[k]});
        }
    }

    int ans = 0;
    if(vis1[ti][tj]) {
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