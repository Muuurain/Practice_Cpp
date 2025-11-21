#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    vector<ll> m(n), r(n);
    for(auto& i : m) cin >> i;
    for(auto& i : r) cin >> i;

    ll term = m[0];
    for(int i = 1; i < m.size(); i++) {
        ll aid = gcd(term, m[1]);
        term = m[i] * m [i - 1] / aid;
    }

    ll mor = (ll)1e6 / term;
    term *= mor;

    ll days = 0;
    for(int i = 1; i < term; i++) {
        for(int j = 0; j < n; j++) {
            if(i % m[j] == r[j]) {
                days++;
                break;
            }
        }
    }

    double ans = (double)days / term;

    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}