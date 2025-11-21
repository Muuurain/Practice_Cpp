#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;
void solve() {
    ll n;
    cin >> n;

    vector<ll> num(n);
    vector<ll> uniq(n);
    for (int i = 0; i < n; ++i) {
        cin >> uniq[i];
    }
    num = uniq;

    sort(uniq.begin(), uniq.end());
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
    uniq.shrink_to_fit();
    vector<ll> freq(uniq.size());

    for(auto& x : num) {
        x = lower_bound(uniq.begin(), uniq.end(), x) - uniq.begin();
        freq[x]++;
    }
    ll maxf = 0;
    ll maxfi = 0;
    for(int i = 0; i < freq.size(); i++) {
        if(freq[i] > maxf) {
            maxf = freq[i];
            maxfi = i;
        }
    }

    ll ans = 1;
    if(maxf > n / 2) {
        for(int i = 0; i < freq.size(); i++) {
            if(i == maxfi) ans *= freq[i];
            else ans *= freq[i] + 1;
            ans %= mod;
        }
    }

    else {
        for(int i = 0; i < freq.size(); i++) {
            ans *= freq[i] + 1;
            ans %= mod;
        }
        if(ans == 0) ans = mod - 1;
        else ans -= 1;
    }

    

    if(freq.size() == 1) ans = freq[0];

    cout << ans << '\n';
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