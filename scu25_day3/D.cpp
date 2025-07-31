#include <bits/stdc++.h>
using namespace std;

const int k = 110;
vector <vector <int> > v(k), m(k);
int dp[110][1100];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m1, n;
    cin >> m1 >> n;
    for(int i = 1; i < k; i++) {
        v[i].push_back(0);
        m[i].push_back(0);
    }
    for(int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[c].push_back(b);
        m[c].push_back(a);
    }

    for(int i = 1; i < k; i++) {
        for(int j = 1; j <= m1; j++) {
            for(int z = 0; z < v[i].size(); z++) {
                if(j >= m[i][z]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - m[i][z]] + v[i][z]);
                }
            }
        }
    }

    cout << dp[k - 1][m1] << endl;
    

    return 0;
}