#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double x;
    cin >> x;
    double ans = 0;
    if(x >= 60) {
        ans = 1 + (x - 60) * 0.1;
    }

    cout << fixed << setprecision(2) << ans << '\n';

    return 0;
}