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

    string S;
    cin >> S;
    int op;
    cin >> op;
    int n;
    cin >> n;

    if(op == 0) {
        for(auto& c : S) {
            if(c <= 'Z' && c >= 'A') c = c + ('a' - 'A');
        }
    }
    while(n--) {
        string os;
        cin >> os;
        string ts = os;
        if(op == 0) {
            for(auto& c : ts) {
                if(c <= 'Z' && c >= 'A') c = c + ('a' - 'A');
            }
        }
        ts += " ";
        for(int i = 0; i < ts.size() - 1; i++) {
            if(ts[i] == S[0]) {
                int value = 1;
                for(int j = 1; j < S.size(); j++) {
                    if(ts[i + j] != S[j]) {
                        value = 0;
                        break;
                    }
                }
                if(value) {
                    cout << os << '\n';
                    break;
                }
            }
        }
    }


    return 0;
}