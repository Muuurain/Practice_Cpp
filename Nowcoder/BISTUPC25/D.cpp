#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    if(n < 5) {
        cout << -1 << '\n';
        return 0;
    }
    int m = n - 1 + (int)ceil((double)(n - 1) / 2);
    cout << m << endl;

    for(int i = 2; i <= n; i++) {
        cout << 1 << ' ' << i << '\n';
    }
    int i = 2;
    for(; i <= n - 1; i += 2) {
        cout << i << ' ' << i + 1 << '\n';
    }
    if(i != n + 1) {
        cout << i << ' ' << i - 1 << '\n';
    }

    return 0;
}