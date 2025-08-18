#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    int ans = 0;
    cin >> n >> m;
    ans = max(n, m) + 1;
    cout << ans << endl;
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