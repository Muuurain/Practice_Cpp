#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if(!(n & 1)) {
        for(int i = 1; i * 2 <= n; i++) {
            cout << i << " " << i << " ";
        }
        cout << endl;
    }
    else if(n >= 26) {
        int sign = 3;
        int t = 0;
        for(int i = 1; i <= n; i++) {
            if(i == 1) cout << 1 << " ";
            else if(i == 10) cout << 1 << " ";
            else if(i == 26) cout << 1 << " ";
            else if(i == 11) cout << 2 << " ";
            else if(i == 27) cout << 2 << " ";
            else {
                cout << sign << " ";
                t++;
                if(t == 2) {
                    t = 0;
                    sign++;
                }
            }
        }
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}