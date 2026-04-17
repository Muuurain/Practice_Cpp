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

const int N = 1e5 + 10;
struct silk {
    int od;
    int di;
};

bool cmp(const silk& s1, const silk& s2) {
    if(s1.od != s2.od) return s1.od < s2.od;
    else return s1.di < s2.di;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int p = 0;
    int sum = 0;
    vector<silk> si(N);
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        sum += k;
        while(k--) {
            cin >> si[p].di;
            si[p++].od = i;
        }
    }
    sort(si.begin(), si.begin() + sum, cmp);

    int pre[N];
    int next[N] = {0};

    int elem = 0;
    for(int i = 0; i < sum - 1; i++) {
        if(si[i].od != si[i + 1].od) {
            for(int j = i - elem; j <= i; j++) {
                next[j] = i + 1;
            }
            elem = 0;
        }
        else elem++;
    }

    elem = 0;
    for(int i = sum - 1; i > 0; i--) {
        if(si[i].od != si[i - 1].od) {
            for(int j = i + elem; j >= i; j--) {
                pre[j] = i - 1;
            }
            elem = 0;
        }
        else elem++;
    }

    for(int i = 0; i <= elem; i++) {
        pre[i] = sum - 1;
    }

    auto check1 = [&](int m, int l) {
        return si[m].di > l;
    };

    auto check2 = [&](int m, int r) {
        return si[m].di < r;
    };

    int ans = 0;
    for(int i = 0; i < sum - 1; i++) {
        if(si[i].od != si[i + 1].od) continue;
        int lo = (pre[pre[i]] + 1) % sum;
        int hi = pre[i];
        int l = si[i].di;
        int r = si[i + 1].di;
        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (check1(m, l)) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }
        
        if(si[hi].di < l) continue;
        int t = hi;
        lo = next[i];
        hi = (next[next[i]] - 1 + sum) % sum;
        while (lo < hi) {
            int m = (lo + hi + 1) / 2;
            if (check2(m, r)) {
                lo = m;
            } else {
                hi = m - 1;
            }
        }
        if(si[lo].di > r) continue;
        ans+= max(t - lo + 1, 0);
    }

    cout << ans << '\n';
    
    return 0;
}