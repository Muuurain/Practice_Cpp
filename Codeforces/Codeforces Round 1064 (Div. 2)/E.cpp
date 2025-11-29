#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> num(n);
    for(auto& i : num) cin >> i;
    sort(num.begin(), num.end(), [&](int& a, int&b) {
        return a > b;
    });
    int nn = min(n, 30);
    while(q--) {
        int c;
        cin >> c;
        vector<int> b(nn); 
        ll ans = 0;
        for(int i = 0; i < nn; i++) {
            b[i] = num[i];
        }
        for(int i = 29; ~i; i--) {
            int cc = 0;
            for(auto j : b) cc += (j >> i) & 1;
            int cret = (c >> i) & 1;
            if(cc > cret) break;
            if(cc == cret) for(auto& j : b) j &= ~(1 << i);
            else {
                int index = 0;
                for(int i = 1; i < nn; i++) {
                    if(b[i] > b[index]) index = i;
                }
                ans += (1 << i) - b[index];
                b[index] = 0;
            }
        }
        cout << ans << '\n';
    }
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