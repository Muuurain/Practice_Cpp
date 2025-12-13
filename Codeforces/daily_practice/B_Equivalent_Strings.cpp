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

string smallest(const string& s) {
        if(s.length() & 1) return s;
        string ss1 = smallest(s.substr(0, s.length() / 2));
        string ss2 = smallest(s.substr(s.length() / 2, s.length() / 2));
        return ss1 < ss2 ? ss1 + ss2 : ss2 + ss1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    if(smallest(s1) == smallest(s2)) cout << "YES" << '\n';
    else cout << "NO" << '\n'; 

    return 0;
}