#include <bits/stdc++.h>

using namespace std;

int mp[12][12];
int cpmp[12][12];
int N;
int max1, max2;
queue<int> doit;

void dfs(int x, int y) {
    
}

int main() {
    cin >> N;
    while(1) {
        int x, y, num;
        scanf("%d%d%d", &x, &y, &num);
        if(x == 0 && y == 0 && num == 0) {
            break;
        }
        mp[x][y] = num;
    }
    memcpy(cpmp, mp, sizeof(mp));
    


    return 0;
}