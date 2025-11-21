#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n), f(n);
    ll sum = 0, ans = LLONG_MAX;
    for(auto& i : a) cin >> i;
    for(auto& i : c) {
        cin >> i;
        sum += i;
    }

    for(int i = 0; i < n; i++) {
        f[i] = c[i];
        for(int j = 0; j < i; j++) {
            if(a[j] <= a[i]) f[i] = max(f[i], f[j] + c[i]);
            ans = min(ans, sum - f[i]);
        }
        ans = min(ans, sum - f[i]);
    }

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