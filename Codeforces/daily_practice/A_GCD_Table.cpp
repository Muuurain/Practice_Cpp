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
    int nn = n * n;
    vector<int> num(nn);
    for(auto& i : num) cin >> i;
    sort(num.begin(), num.end());

    vector<int> ans(n);
    vector<int> vis(nn);
    vector<int> vvis(nn);
    int pa = 0;
    int pn = num.size() - 1;
    ans[pa++] = num[pn--];
    
    if(pa < n) {
        ans[pa++] = num[pn--];
        int era = lower_bound(num.begin(), num.end(), gcd(ans[0], ans[1])) - num.begin();
        vis[era] = 1;
        vis[era + 1] = 1;
        vvis[era] += 2;
    }
    
    while(pa < n) {
        while(vis[pn]) pn--;
        ans[pa++] = num[pn--];
        for(int i = 0; i < pa - 1; i++) {
            int era = lower_bound(num.begin(), num.end(), gcd(ans[i], ans[pa - 1])) - num.begin();
            int eera = era + vvis[era];
            vvis[era] += 2;
            vis[eera] = 1;
            vis[eera + 1] = 1;
        }
    }

    for(auto& i : ans) cout << i << " ";
    cout << endl;

    return 0;
}