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
    string n1, n2;
    cin >> n1 >> n2;
    n1 = " " + n1;
    n2 = " " + n2;
    bool value = true;
    for(int i = 3; i <= n; i++) {
        if(i & 1) {
            if(n2[i] == '<' && n1[i - 1] == '<') {
                value = false;
                break;
            }
        }
        else {
            if(n1[i] == '<' && n2[i - 1] == '<') {
                value = false;
                break;
            }
        }
    }
    if(value) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
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