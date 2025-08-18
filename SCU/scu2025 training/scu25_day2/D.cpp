#include <bits/stdc++.h>
using namespace std;

queue<pair <int, int> > mp;
int ret[410][410];
int mv[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    memset(ret, -1, sizeof(ret));
    int mn = 0;
    ret[x][y] = mn++;
    for(int i = 0; i < 8; i++) {
        if(x + mv[i][0] > 0 && y + mv[i][1] > 0 && x + mv[i][0] <= n && y + mv[i][1] <= m) {
            mp.push({x + mv[i][0], y + mv[i][1]});
            ret[x + mv[i][0]][y + mv[i][1]] = mn;
        }
    }
    while(!mp.empty()) {
        pair<int, int> t = mp.front();
        mp.pop();
        x = t.first;
        y = t.second;
        mn = ret[x][y] + 1;
        for(int i = 0; i < 8; i++) {
            if(x + mv[i][0] > 0 && y + mv[i][1] > 0 && x + mv[i][0] <= n && y + mv[i][1] <= m && ret[x + mv[i][0]][y + mv[i][1]] == -1) {
                mp.push({x + mv[i][0], y + mv[i][1]});
                ret[x + mv[i][0]][y + mv[i][1]] = mn;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    


    return 0;
}