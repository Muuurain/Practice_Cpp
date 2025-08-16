#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    ll num;
    cin >> num;
    bool value = true;
    ll t = num;
    int cnt = 0;
    int aim = 0;
    while(t) {
        cnt++;
        int te = t % 10;
        t /= 10;
        if(te & 1) continue;
        else {
            value = false;
            aim = cnt;
        }
    }
    if(value) cout << 0 << endl;
    else {
        ll ans = num / pow(10, aim - 1);
        ans++;
        aim--;
        while(aim) {
            aim--;
            ans = ans * 10 + 1;
        }
        ans -= num;
        cout << ans << endl;
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