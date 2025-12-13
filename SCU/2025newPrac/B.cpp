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
    ll son = 0;
    cin >> son;
    bool value = true;
    for(int i = 1; i < n; i++) {
        int d;
        cin >> d;
        son--;
        if(son < 0) {
            value = false;
        } 
        d--;
        son += d;
    }
    if(son != 0) {
        value = false;
    }
    if(value) cout << "Yes" << '\n';
    else cout << "No" << '\n';
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