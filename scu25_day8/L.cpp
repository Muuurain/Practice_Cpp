#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &i : a) cin >> i;
    for(int i = 1; i < n; i++) b[i] = a[i - 1];
    b[0] = a[n - 1];
    for(int i : b) cout << i << " ";
    cout << endl;
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