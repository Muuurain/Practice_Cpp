#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    bool value = false;
    vector<int> a(110);
    while(n--) {
        int t;
        cin >> t;
        a[t]++;
        if(a[t] > 1) value = true;
    }
    if(value) cout << "Yes" << endl;
    else cout << "No" << endl;
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