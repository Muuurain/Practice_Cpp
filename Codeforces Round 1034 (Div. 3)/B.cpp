#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    int ret = a[j - 1];
    sort(a.begin(), a.end());
    if(a[n - 1] == ret) cout << "YES" << endl;
    else if(k > 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}