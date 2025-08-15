#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<vector<int> > ans(N, vector<int>(N));
    int n;
    cin >> n;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0) ans[i][j] = 1;
            else if(j == 0) ans[i][j] = ans[i - 1][j + 1];
            else ans[i][j] = ans[i - 1][j + 1] + ans[i][j - 1];
        }
    }
    cout << ans[n][0] << endl;

    return 0;
}