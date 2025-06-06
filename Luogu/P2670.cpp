#include <bits/stdc++.h>

using namespace std;

char mp[110][110];
int rund[][2] = {{0, 1}, {1, 1}, {1, 0}, {-1, 0},
                 {-1, 1}, {-1, -1}, {1, -1}, {0, -1}};

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mp[i][j] == '*');
            else {
                int bomb = 0;
                for(int k = 0; k < 8; k++) {
                    if(mp[i + rund[k][0]][j + rund[k][1]] == '*') {
                        bomb++;
                    }
                }
                mp[i][j] = bomb + '0';
            }
            cout << mp[i][j];
        }
        cout << endl;
    }


    return 0;
}