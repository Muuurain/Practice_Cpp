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
    vector<int> num(n + 5);
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.begin() + n);
    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if(num[i + 1] - num[i] == 1) ans++;
    }

    cout << ans << '\n';

    return 0;
}