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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 5);
    for(auto& i : a) cin >> i;
    for(int i = 1; i <= n; i++) cin >> b[i];
    int st1 = a[0];
    int now = st1;
    for(int i = 0; i <= n; i++) {
        now += b[i];
        now -= a[i];
        if(now < 0) {
            st1 -= now;
            now = 0;
        }
    }
    vector<int> w(n + 5);
    w[0] = st1;
    vector<int> sp(n + 5);
    sp[0] = st1 - a[0];
    for(int i = 1; i <= n; i++) {
        sp[i] = sp[i - 1] + b[i] - a[i];
    }
    vector<int> minn(n + 5);
    minn[n] = sp[n];
    for(int i = n - 1; ~~i; i--) {
        minn[i] = min(minn[i + 1], sp[i]);
    }
    for(int i = 1; i <= n; i++) {
        w[i] = st1 - min(minn[i] - b[i], 0);
    }
    for(int i = 1; i <= n; i++) {
        cout << w[i] << ' ';
    }

    return 0;
}