#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, l;
    cin >> l >> n;
    int mintime = 0;
    int maxtime = 0;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        mintime = max(min(t, l - t + 1), mintime);
        maxtime = max(max(t, l - t + 1), maxtime);
    }
    cout << mintime << " " << maxtime << '\n';

    return 0;
}