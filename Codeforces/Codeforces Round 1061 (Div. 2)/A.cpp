#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    int ret = 0;
    while(n > 2) {
        ret += n / 3;
        if(n % 3 == 1) n = n / 3 + 1;
        else if(n % 3 == 2) n = n / 3 + 2;
        else n = n / 3;
    }
    cout << ret << '\n';
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