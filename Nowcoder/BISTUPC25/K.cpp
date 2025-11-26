#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> ene(n + 5);
    for(int i = 1; i <= n; i++) {
        cin >> ene[i];
    }
    auto check = [&](int m) {
        ll now = m;
        for(int i = 1; i <= n; i++) {
            if(now > ene[i]) now++;
            else if(now < ene[i]) now--;
        }
        return now > m;
    };
    int lo = 1, hi = *max_element(ene.begin(), ene.end()) + 1;
    while (lo < hi) {
        int m = (lo + hi) / 2;
        if (check(m)) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    cout << lo << "\n";
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