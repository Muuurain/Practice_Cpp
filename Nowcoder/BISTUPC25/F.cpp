#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double n;
    cin >> n;
    double ans = 0.5 * (1 + (n - 1) / (2 * n - 1));


    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}