#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> num(n);
    for(int& i : num) cin >> i;
    sort(num.begin(), num.end());
    int ret = 0;
    int p = n / 2;
    for(int i = 0; i < p; i++) {
        ret = max(ret, num[i * 2 + 1] - num[i * 2]);
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