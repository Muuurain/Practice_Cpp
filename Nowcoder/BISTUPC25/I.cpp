#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    if(n & 1) {
        for(int i = 0; i < n; i++) {
            cout << 'a';
        }
    }
    else {
        for(int i = 0; i < n - 1; i++) {
            cout << 'a';
        }
        cout << 'b';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}