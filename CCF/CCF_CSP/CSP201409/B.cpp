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

struct sq{
    int x1, y1, x2, y2;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<sq> s(n + 5);
    for(int i = 0; i < n; i++) {
        cin >> s[i].x1 >> s[i].y1 >> s[i].x2 >> s[i].y2;
    }
    int ans = 0;
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            for(int k = 0; k < n; k++) {
                if(s[k].x1 <= i - 1 && s[k].x2 >= i && s[k].y1 <= j - 1 && s[k].y2 >= j) {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}