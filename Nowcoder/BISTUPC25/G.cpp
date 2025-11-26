#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double p1 = (y1 - y2) / (x1 - x2), p2 = (y2 - y3) / (x2 - x3);
    double a = (p1 - p2) / (x1 - x3);
    if(a > 0) cout << "UP" << '\n';
    else cout << "DOWN" << '\n';
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