#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        scanf("%1d", &a[i]);
        if(a[i]) cnt++;
    }
    if(cnt <= k) cout << "Alice" << endl;
    else if(k * 2 > n) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}