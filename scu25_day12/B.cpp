#include <bits/stdc++.h>
using namespace std;

const int N = 105;
typedef long long ll;
ll dis[N][N];
ll org[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            dis[i][j] = org[i][j] = INT_MAX;
        }
    }
    ll ans = INT_MAX;
    while(m--) {
        ll u, v, d;
        cin >> u >> v >> d;
        org[u][v] = org[v][u] = min(d, org[u][v]);
        dis[u][v] = dis[v][u] = min(d, dis[u][v]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            for(int k = j + 1; k < i; k++) {
                ans = min(ans, dis[j][k] + org[j][i] + org[i][k]);
            }
        }
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                dis[j][k] = dis[k][j] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }
    if(ans == INT_MAX) {
        cout << "No solution." << endl;
    }
    else cout << ans << endl;


    return 0;
}