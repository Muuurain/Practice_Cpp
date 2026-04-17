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
    int x, y;
    cin >> x >> y;
    int sum = x + y - 1;
    if((x + y) & 1) {
        if(y == 0) {
            cout << "NO" << '\n';
            return;
        }
        y--;
    }
    else {
        if(x == 0) {
            cout << "NO" << '\n';
            return;
        }
        x--;
    }
    if(x > sum / 2) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    int node = 2;
    for(int i = 0; i < y; i++) {
        cout << 1 << " " << node++ << '\n';
    }
    int nodex = node;
    node = 2;
    for(int i = 0; i < x; i++) {
        cout << node++ << " " << nodex++ << '\n';
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