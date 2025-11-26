#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, q, k;
    cin >> n >> m >> q >> k;

    vector<int> row(n + 5), column(m + 5);
    while(q--) {
        int t;
        cin >> t;
        row[t] = 1;
    }
    while(k--) {
        int t;
        cin >> t;
        column[t] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int ans = 0;
            if(row[i] == 1) ans += 1;
            if(column[j] == 1) ans += 2;
            if(ans == 1) {
                cout << '-';
            }
            else if(ans == 2) {
                cout << '|';
            }
            else if(ans == 3) {
                cout << '+';
            }
            else {
                cout << 0;
            }
        }
        cout << '\n';
    }

    return 0;
}