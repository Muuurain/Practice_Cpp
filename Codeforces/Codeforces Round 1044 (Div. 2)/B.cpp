#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> g(n);
    for(int &i : g) cin >> i;
    sort(g.begin(), g.end());
    ll ans = 0;
    if(n & 1) {
        for(int i = 0; i < n; i += 2) {
            ans += g[i];
        }
    }
    else {
        for(int i = 1; i < n; i += 2) {
            ans += g[i];
        }
    }
    cout << ans << endl;
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