// template_pre_cf

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


// template_gen_primes

vector<ll> pri;
vector<bool> not_prime;
void pre(int cnt)
{
    pri.clear();
    not_prime.clear();
    for (long long i = 2; pri.size() < cnt; ++i)
    {
        if (i >= not_prime.size())
            not_prime.resize(i + 1);
        if (!not_prime[i])
            pri.push_back(i);
        for (int p : pri)
        {
            if (i > 1e9 / p)
                break;
            long long num = i * p;
            if (num >= not_prime.size())
                not_prime.resize(num + 1);
            not_prime[num] = 1;
            if (i % p == 0)
                break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i] = pri[i] * pri[i + 1];
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    const int maxn = 1e4 + 5;
    cin >> t;
    pre(maxn);
    while(t--) solve();

    return 0;
}