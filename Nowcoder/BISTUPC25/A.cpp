#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    ll ans = ((ll)a[n - 2] * (n - 1));
    cout << ans << '\n';
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