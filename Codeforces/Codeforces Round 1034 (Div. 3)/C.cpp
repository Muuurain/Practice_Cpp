#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ma(n), mi(n);
    int mii = a[0];
    int mai = a[n - 1];
    for(int i = 0; i < n; i++) {
        mii = min(mii, a[i]);
        mi[i] = mii;
    }
    for(int i = n - 1; i >= 0; i--) {
        mai = max(mai, a[i]);
        ma[i] = mai;
    }
    cout << 1;
    for(int i = 1; i < n - 1; i++) {
        if(a[i] >= ma[i + 1]) cout << 1;
        else if(a[i] <= mi[i - 1]) cout << 1;
        else cout << 0;
    }
    cout << 1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}