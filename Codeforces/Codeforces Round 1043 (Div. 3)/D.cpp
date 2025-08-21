#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll sumd(ll n) {
    if (n < 0) return 0;
    ll res = 0;
    ll base = 1;
    while (base <= n) {
        ll high = n / (base * 10);
        ll curr = (n / base) % 10;
        ll low = n % base;
        res += high * base * 45;
        res += (curr * (curr - 1) / 2) * base;
        res += curr * (low + 1);
        base *= 10;
    }
    return res;
}

ll sumdd(int d) {
    if (d == 1) return 45;
    ll pow10 = 1;
    for (int i = 0; i < d - 2; ++i) {
        pow10 *= 10;
    }
    return 45 * pow10 * (10 + 9 * (d - 1));
}

void solve() {
    ll k;
    cin >> k;
    ll st = 0;
    int d = 1;
    while (true) {
        ll start = 1;
        for (int i = 0; i < d - 1; ++i) {
            start *= 10;
        }
        ll count = 9 * start;
        ll prenum = d;
        ll totald = count * prenum;
        if (k <= totald) {
            break;
        }
        st += sumdd(d);
        k -= totald;
        ++d;
    }
    
    ll start = 1;
    for (int i = 0; i < d - 1; ++i) {
        start *= 10;
    }
    ll m = k / d;
    int r = k % d;
    
    if (m > 0) {
        ll end = start + m - 1;
        st += sumd(end) - sumd(start - 1);
    }
    
    if (r > 0) {
        ll num = start + m;
        string s = to_string(num);
        ll sum_r = 0;
        for (int i = 0; i < r; ++i) {
            sum_r += s[i] - '0';
        }
        st += sum_r;
    }
    
    cout << st << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}