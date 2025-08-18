#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x;
    cin >> x;
    int ans = 0;
    int ret = 0;
    for(int i = 1;  i < x; i++) {
        int t = gcd(i, x) + i;
        if(t > ans) {
            ret = i;
        }
    }
    cout << ret << endl;
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