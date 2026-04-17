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

    int n, k, pp, x, y;
    cin >> n >> k >> pp >> x >> y;

    int sum = 0;
    vector<int> sco(k);
    for(auto& i : sco) cin >> i;
    sort(sco.begin(), sco.end());
    if(k <= n / 2) {
        if(lower_bound(sco.begin(), sco.end(), y) != sco.end()) {
            int p = lower_bound(sco.begin(), sco.end(), y) - sco.begin() + 1;
            for(int i = p; i < (n / 2 + 1); i++) {
                sco.push_back(1);
            }
            sco.resize(n, y);
        }
        else {
            for(int i = k + 1; i <= n / 2; i++) {
                sco.push_back(1);
            }
            sco.resize(n, y);
        }
    }
    else {
        if(lower_bound(sco.begin(), sco.end(), y) != sco.end()) {
            int p = lower_bound(sco.begin(), sco.end(), y) - sco.begin() + 1;
            for(int i = p; i < (n / 2 + 1); i++) {
                sco.push_back(1);
            }
            sco.resize(n, y);
        }
        else sco.resize(n, y);
    }
    vector<int> tep = sco;
    sort(tep.begin(), tep.end());

    for(auto& i : sco) {
        sum += i;
    }
    if(sum <= x && tep[n / 2] >= y && tep[n - 1] <= pp) {
        for(int i = k; i < n; i++) {
            cout << sco[i] << ' ';
        }
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}