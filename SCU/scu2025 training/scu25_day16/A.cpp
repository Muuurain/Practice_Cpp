#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    ll n, e, d;
    cin >> n >> e >> d;
    if(((n - e*d + 2) * (n - e*d + 2) - 4 * n) < 0) {
        cout << "NO" << endl;
        return;
    }
    ll part1 = n - e * d + 2;
    ll part2 = sqrt((n - e*d + 2) * (n - e*d + 2) - 4 * n);
    if(part2 * part2 != (n - e*d + 2) * (n - e*d + 2) - 4 * n) {
        cout << "NO" << endl;
        return; 
    }
    ll p = (part1 - part2) / 2;
    if(p < 0) {
        cout << "NO" << endl;
        return; 
    }
    ll q = (part1 + part2) / 2;
    if(part1 - part2 != 2 * p || part1 + part2 != 2 * q) {
        cout << "NO" << endl;
        return; 
    }
    cout << p << " " << q << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> k;
    while(k--) solve();
    
    return 0;
}