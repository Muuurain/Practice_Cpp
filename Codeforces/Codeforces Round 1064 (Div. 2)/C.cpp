#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i : a) cin >> i;
    int maxa = *max_element(a.begin(), a.end());

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(i == n - 1) ans += max(a[i], a[0]);
        else ans += max(a[i], a[i + 1]);
    }

    ans -= maxa;
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