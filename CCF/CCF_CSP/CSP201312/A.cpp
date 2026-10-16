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

const int N = 1e4 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> num(N);

    int n;
    cin >> n;
    while(n--) {
        int t;
        cin >> t;
        num[t]++;
    }
    int target = 0;
    int maxt = num[0];
    for(int i = 1; i < N; i++) {
        if(maxt < num[i]) {
            target = i;
            maxt = num[i];
        }
    }

    cout << target << '\n';

    return 0;
}