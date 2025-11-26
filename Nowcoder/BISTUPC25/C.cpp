#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, m;
    cin >> n >> m;
    if(!(n & 1) && !(m & 1)) cout << "NO" << '\n';
    else cout << "YES" << '\n';
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