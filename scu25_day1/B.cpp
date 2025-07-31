#include <bits/stdc++.h>
using namespace std;

#define MOD 9901
vector<int> pri;
bool not_prime[50001];

void pre(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!not_prime[i]) {
      pri.push_back(i);
    }
    for (int pri_j : pri) {
      if (i > n / pri_j) break;
      not_prime[i * pri_j] = true;
      if (i % pri_j == 0) {
        break;
      }
    }
  }
}
int mypow(int a, long long b) {
    int ans = 1;
    a %= MOD;
    while (b) {
        if (b & 1) ans = (long long)ans * a % MOD;
        a = (long long)a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int cal(int p, long long cnt) {
    if (p % MOD == 1) {
        return (cnt + 1) % MOD;
    }
    int numerator = (mypow(p, cnt + 1) - 1 + MOD) % MOD;
    int denominator = (p - 1) % MOD;
    int inv_denominator = mypow(denominator, MOD - 2);
    return (long long)numerator * inv_denominator % MOD;
}
vector<long long> fac, facn;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    if(a < 2) {
        cout << a << endl;
        return 0;
    }
    pre(50000);
    for(int i = 0; i < pri.size(); i++) {
        if(a % pri[i] == 0) {
            fac.push_back(pri[i]);
            facn.push_back(b);
            a /= pri[i];
        }
        while(a % pri[i] == 0) {
            facn.back() += b;
            a /= pri[i];
        }
        if(a == 1) break;
    }
    if(a != 1) {
        fac.push_back(a);
        facn.push_back(b);
    }
    long long ret = 1;
    for(int i = 0; i < fac.size(); i++) {
        ret *= cal(fac[i], facn[i]);
        ret %= MOD;
    }
    cout << ret << endl;
    
    return 0;
}