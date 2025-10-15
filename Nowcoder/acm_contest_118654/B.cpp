#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double n, x, a, b;
    cin >> n >> x >> a >> b;
    double ret = n * (x / 100.0 * a + (100 - x) / 100.0 * b);
    cout << fixed << setprecision(2) << ret << '\n';
    
    return 0;
}