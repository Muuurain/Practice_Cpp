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
    string s;
    cin >> s;
    
    int sd = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            sd = i;
            break;
        }
    }

    int ed = 0;
    for(int i = n - 1; ~i; i--) {
        if(s[i] == '1') {
            ed = (n - 1) - i;
            break;
        }
    }

    int d = 0;
    int ans = ed + sd;
    for(int i = sd + 1; i < n - 1 - ed; i++) {
        if(s[i] == '0') {
            d++;
            ans = max(ans, d);
        }
        else {
            d = 0;
        }
    }


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