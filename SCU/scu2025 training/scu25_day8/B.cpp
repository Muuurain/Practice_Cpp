#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    ll n, k;
    cin >> n >> k;
    if(n < k) {
        cout << "NO" << endl;
    }
    else if(n == k) {
        cout << "YES" << endl << "1" << endl << "1" << endl;
    }
    else if(n <= (k - 1) * 2){
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl << 2 << endl << n - k + 1 << " " << 1 << endl;
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