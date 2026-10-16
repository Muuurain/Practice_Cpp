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
    vector<ll> rec(n + 10);
    for(int i = 0; i < n; i++) {
        cin >> rec[i];
    }
    //rec.push_back(0); rec(n + 10)已经包含末尾的哨兵'0';
    stack<int> s;
    ll ans = 0;
    for(int i = 0; i <= n; i++) {
        while(!s.empty() && rec[s.top()] > rec[i]) {
            int aim = s.top();
            s.pop();
            int right = i;
            int left = s.empty() ? -1 : s.top();
            ll width = right - left - 1;
            ll height = rec[aim];
            ans = max(ans, height * width);
        }

        s.push(i);
    }

    cout << ans << '\n';

    return 0;
}