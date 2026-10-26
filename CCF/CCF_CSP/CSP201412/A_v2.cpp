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
// 补充支持 unordered_map 的调试输出重载
template <typename K, typename V>
void debug_impl(const unordered_map<K, V>& mp) {
    cout << "{";
    bool first = true;
    for (const auto& kv : mp) {
        if (!first) cout << ", ";
        first = false;
        debug_impl(kv.first);
        cout << ": ";
        debug_impl(kv.second);
    }
    cout << "}";
}
#define debug(x) do { \
    cout << "debug(" << #x << "): "; \
    debug_impl(x); \
    cout << '\n'; \
} while(0)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    unordered_map<int, int> num;
    num.reserve(n); // 预分配桶空间，避免多次动态扩容与重哈希（Rehash）

    while (n--) {
        int t;
        cin >> t;
        cout << ++num[t] << (n ? ' ' : '\n');
    }

    return 0;
}