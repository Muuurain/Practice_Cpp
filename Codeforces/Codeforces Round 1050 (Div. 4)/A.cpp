#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int x, n;
    cin >> x >> n;
    if(n & 1) cout << x;
    else cout << 0;
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