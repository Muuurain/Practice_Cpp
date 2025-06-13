#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    short n, m, c, k;
    cin >> n >> m >> c >> k;
    short dox1[k + 1] = {0};
    short dox2[k + 1] = {0};
    short doy1[k + 1] = {0};
    short doy2[k + 1] = {0};
    int dop[k + 1] = {0};
    short doxt[k + 1] = {0};
    short doyt[k + 1] = {0};
    short mp[n + 1][m + 1] = {0};
    int vis[n + 1][m + 1];
    memset(vis, 0, sizeof(vis));
    memset(mp, -1, sizeof(mp));
    for(short i = 1; i <= k; i++) {
        cin >> dox1[i] >> doy1[i] >> dox2[i] >> doy2[i] >> dop[i] >> doxt[i] >> doyt[i];
    }
    short cmp[c + 1][c + 1] = {0};
    for(short i = 1; i <= c; i++) {
        for(short j = 1;j <= c; j++) {
            cin >> cmp[i][j];
        }
    }
    for(short i = 1; i <= k; i++) {
        for(short j = dox1[i]; j <= dox2[i]; j++) {
            for(short l = doy1[i]; l <= doy2[i]; l++) {
                int p = dop[i];
                if(p < vis[j][l]) continue;
                vis[j][l] = p;
                mp[j][l] = cmp[doxt[i] + j - dox1[i]][doyt[i] + l - doy1[i]];
            }
        }
    }
    for(short i = 1; i <= n; i++) {
        for(short j = 1; j <= m; j++) {
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}