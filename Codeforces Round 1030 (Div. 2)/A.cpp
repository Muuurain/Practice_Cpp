#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int num = n - k;
    for(int  i = 0; i < k; i++) {
        cout << 1;
    }
    for(int i = 0; i < num; i++) {
        cout << 0;
    }
    cout << endl;



}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}