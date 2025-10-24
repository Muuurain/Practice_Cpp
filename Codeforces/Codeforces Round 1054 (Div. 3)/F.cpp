#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll mid, ll d, ll h) {
    ll health = h + mid;
    ll move = d / (mid + 1);
    ll remain = d % (mid + 1);
    ll consume = (mid + 1 - remain) * (1 + move) * move / 2 + remain * (2 + move) * (move + 1) / 2;
    return consume < health;
}

void solve() {
    ll h, d;
    cin >> h >> d;
    ll diff = 0;
    if(h == 1) {
        h++;
        diff = 1;
    }
    ll l = 0, r = d - 1;
    ll ret = 0;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(check(mid, d, h)) {
            ret = mid + d;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    ret += diff;
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