// template_pre_standard

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


// template_myPow

ll mypow(ll a, ll b, ll p) {
    ll ans = 1;
    a %= p;
    while(b) {
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    ll a, b;
    cin >> a >> b;
    if(s.length() < 2) {
        cout << "NO" << endl;
        return 0;
    }

    vector<ll> dpa(s.length()), dpb(s.length());
    dpa[0] = s[0] - '0';
    if(dpa[0] == 0) {
        cout << "NO" << endl;
        return 0;
    }
    dpa[0] %= a;
    for(int i = 1; i < s.length(); i++) {
        dpa[i] = dpa[i - 1] * 10 + (s[i] - '0');
        dpa[i] %= a;
    }
    vector<bool> value(s.length(), true);
    for(int i = s.length() - 2; ~i; i--) {
        if(s[i + 1] == '0') {
            value[i] = false;
        }
        dpb[i] = dpb[i + 1] + mypow(10, s.length() - 2 - i, b) * (s[i + 1] - '0');
        dpb[i] %= b;
    }

    for(int i = 0; i < s.length() - 1; i++) {
        if(value[i] && dpa[i] == 0 && dpb[i] == 0) {
            cout << "YES" << endl;
            for(int j = 0; j <= i; j++) {
                cout << s[j];
            }
            cout << endl;
            for(int j = i + 1; j < s.length(); j++) {
                cout << s[j];
            }
            cout << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}