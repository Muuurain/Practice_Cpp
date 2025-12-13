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
    vector<int> num(n);
    for(auto& i : num) cin >> i;
    int value = 1;
    while(value) {
        value = 0;
        int change;
        for(int i = 1; i < num.size(); i++) {
            if(num[i] < num[i - 1]) {
                if(num[i] >= num[i - 1] % 10) {
                    value = 1;
                    vector<int> t(num.size() + 1);
                    for(int j = 0; j < i - 1; j++) {
                        t[j] = num[j];
                    }
                    t[i - 1] = num[i - 1] / 10;
                    t[i] = num[i - 1] % 10;
                    for(int j = i + 1; j < t.size(); j++) {
                        t[j] = num[j - 1];
                    }
                    num = t;
                }
                else {
                    cout << "NO" << '\n';
                    return;
                }
                break;
            }
        }
    }
    cout << "YES" << '\n';
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