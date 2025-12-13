// template_pre_cf

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template <typename T>
void debug_impl(const T& val) {
    cout << val;
}
template <typename T>
void debug_impl(const vector<T>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) cout << ", ";
        debug_impl(vec[i]);
    }
    cout << "]";
}
#define debug(x) do { \
    cout << "debug(" << #x << "): "; \
    debug_impl(x); \
    cout << '\n'; \
} while(0)

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll nume = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if((a[i] & 1) == 0) nume++;
    }
    ll numo = n - nume;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] & 1) {
            ans = a[i];
            break;
        }
    }
    if(ans == 0) {
        for(int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
        cout << '\n';
    }
    else {
        int pos = 0;
        cout << ans << ' ';
        vector<ll> sum(n + 5);
        sum[0] = ans;
        for(int i = 1; i < nume + 1; i++) {
            while(pos < n) {
                if(a[pos] & 1) {
                    pos++;
                    continue;
                }
                ans += a[pos];
                pos++;
                break;
            }
            sum[i] = ans;
            cout << ans << ' ';
        }
        for(int i = nume + 1; i < n; i++) {
            int sm = i + 1;
            int out = sm - nume - 1;
            if(out & 1) {
                out++;
            }
            if(out > numo - 1) {
                cout << 0 << ' ';
            }
            else {
                if(sm - out - 1  < 0) cout << 0 << ' ';
                else cout << sum[sm - out - 1] << ' ';
            } 
        }
        cout << '\n';
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