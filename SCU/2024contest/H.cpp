#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    int k;
    k = ceil(n / 2.0);
    vector<int> ans(k);
    cout << k << '\n';
    for(int i = n / 2 + 1; i <= n; i++) {
        cout << i << ' ';
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