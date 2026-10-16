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

const int MOD = 11;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    int result = (s[0] - '0') + (s[2] - '0') * 2 + (s[3] - '0') * 3 + (s[4] - '0') * 4 + (s[6] - '0') * 5 + (s[7] - '0') * 6 + (s[8] - '0') * 7 + (s[9] - '0') * 8 + (s[10] - '0') * 9;
    result %= MOD;

    if(result == s[12] - '0' || (result == 10 && s[12] == 'X')) {
        cout << "Right" << '\n';
    }
    else {
        debug(result);
        for(int i = 0; i < s.length() - 1; i++) {
            cout << s[i];
        }
        if(result == 10) {
            cout << "X" << '\n';
        }
        else cout << result << '\n';
    }

    return 0;
}