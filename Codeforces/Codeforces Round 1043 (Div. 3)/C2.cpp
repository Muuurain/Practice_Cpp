#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll p[22];
void solve() {
    ll n, k;
    vector<ll> three;
    cin >> n >> k;
    ll cnt = 0;
    ll ans = 0;
    if(n <= k) {
        ans = 3 * n;
        cout << ans << '\n';
        return;
    }
    while(n) {
        three.push_back(n % 3);
        cnt += three.back();
        n /= 3;
    }
    if(cnt > k) {
        cout << -1 << endl;
        return;
    }
    for(int i = three.size() - 1; i >= 0; i--) {
        bool value = true;
        if(three[i] * 2 + cnt <= k) {
            cnt += three[i] * 2;
            three[i - 1] += three[i] * 3;
            three[i] = 0;
        }
        else {
            value = false;
            ll temp = (k - cnt) / 2;
            three[i] -= temp;
            cnt += temp * 2;
            three[i - 1] += temp * 3;
        }
        if(!value) break;
    }
    for(int i = 0; i < three.size(); i++) {
        if(i == 0) {
            ans += 3 * three[i];
            continue;    
        }
        ans += (p[i + 1] + i * p[i - 1]) * three[i];
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    p[0] = 1;
    for(int i = 1; i < 22; i++) {
        p[i] = p[i - 1] * 3;
    }
    while(t--) solve();

    return 0;
}