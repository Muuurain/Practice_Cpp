#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == b && b == c && c == d) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return;
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