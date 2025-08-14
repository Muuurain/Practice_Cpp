#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), c(n);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    for(int &i : c) cin >> i;
    int now = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] & (~x)) {
            break;
        }
        else {
            now |= a[i];
        }
    }
    for(int i = 0; i < n; i++) {
        if(b[i] & (~x)) {
            break;
        }
        else {
            now |= b[i];
        }
    }
    for(int i = 0; i < n; i++) {
        if(c[i] & (~x)) {
            break;
        }
        else {
            now |= c[i];
        }
    }
    if(now == x) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }


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