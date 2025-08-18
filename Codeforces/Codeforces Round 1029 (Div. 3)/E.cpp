#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &it : a) cin >> it;
    for(int &it : b) cin >> it;
    if(a.back() == b.back()) {
        cout << n << endl;
        return;
    }
    vector<bool> seen(n + 1);
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] == b[i] || seen[a[i]] || seen[b[i]] || a[i] == a[i + 1] || b[i] == b[i + 1]) {
            cout << i + 1 << endl;
            return;
        }
        seen[a[i + 1]] = seen[b[i + 1]] = 1;
    }
    cout << "0" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0;
    cin >> t;

    while(t--) solve();
    return 0;
}