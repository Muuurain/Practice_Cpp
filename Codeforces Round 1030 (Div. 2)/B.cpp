#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << 2 * n - 3 << endl;
    for(int i = 1; i <= n; i++) {
        if(i != 1) {
            cout << i << " " << 1 << " " << i << endl;
        }
        if(i < n - 1) {
            cout << i << " " << i + 1 << " " << n << endl; 
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}