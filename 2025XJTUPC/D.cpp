//D.cpp

#include <bits/stdc++.h>

using namespace std;

char mp[110][110];
char tmp[110][110];
int N, M;
int clos[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool solve1() {
    for(int i = 1; i <= N; i++) {
        for(int j = M / 2 + 1; j <= M; j++) {
            if(mp[i][j] == 'B') {
                mp[i][M - j + 1] = 'B';
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M / 2; j++) {
            if(mp[i][j] == 'B') {
                mp[i][M - j + 1] = 'B';
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M / 2 + 1; j++) {
            if(mp[i][j] == 'B') {
                for(int k = 0; k < 4; k++) {
                    if(mp[i + clos[k][0]][j + clos[k][1]] == 'B') {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool solve2() {
    for(int i = N / 2 + 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(mp[i][j] == 'B') {
                mp[N - i + 1][j] = 'B';
            }
        }
    }
    for(int i = 1; i <= N / 2; i++) {
        for(int j = 1; j <= M; j++) {
            if(mp[i][j] == 'B') {
                mp[N - i + 1][j] = 'B';
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M / 2 + 1; j++) {
            if(mp[i][j] == 'B') {
                for(int k = 0; k < 4; k++) {
                    if(mp[i + clos[k][0]][j + clos[k][1]] == 'B') {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}


int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf(" %c", &mp[i][j]);
        }
    }
    memcpy(tmp, mp, sizeof(mp));
    if(solve1()) {
        cout << "Yes" << endl;
        return 0;
    }
    memcpy(mp, tmp, sizeof(mp));
    if(solve2()) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;

    return 0;
}