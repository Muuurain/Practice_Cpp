#include <bits/stdc++.h>

using namespace std;
char mp[15][15];
int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

int nowf[2];
int nowc[2];

bool isvalue(int x, int y, int way) {
    if(mp[x + dir[way][0]][y + dir[way][1]] == '*' || mp[x + dir[way][0]][y + dir[way][1]] == '\0') {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            scanf(" %c", &mp[i][j]);
            if(mp[i][j] == 'F') {
                nowf[0] = i;
                nowf[1] = j;
            }
            else if(mp[i][j] == 'C') {
                nowc[0] = i;
                nowc[1] = j;
            }
        }
    }
    int time = 0;
    int way1, way2;
    way1 = way2 = 0;
    while(1) {
        if(isvalue(nowc[0], nowc[1], way1)) {
            nowc[0] += dir[way1][0];
            nowc[1] += dir[way1][1];
        }
        else {
            way1 = (way1 + 1) % 4;
        }
        if(isvalue(nowf[0], nowf[1], way2)) {
            nowf[0] += dir[way2][0];
            nowf[1] += dir[way2][1];
        }
        else {
            way2 = (way2 + 1) % 4;
        }
        time++;
        if(nowc[0] == nowf[0] && nowc[1] == nowf[1]) {
            cout << time << endl;
            break;
        }
        if(time > 10000) {
            cout << "0" << endl;
            break;
        }
    }

    return 0;
}