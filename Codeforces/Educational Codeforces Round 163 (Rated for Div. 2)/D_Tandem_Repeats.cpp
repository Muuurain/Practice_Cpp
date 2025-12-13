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
    string s;
    cin >> s;
    for(int i = s.size() - (s.size() & 1); i > 0; i -= 2) {
        int aim = 0;
        for(int j = 0; j + i / 2 < s.size(); j++) {
            if(s[j] == s[j + i / 2] || s[j] == '?' || s[j + i / 2] == '?') aim++;
            else aim = 0;
            if(aim == i / 2) {
                cout << i << '\n';
                return;
            }
        }
    }
    cout << 0 << '\n';
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