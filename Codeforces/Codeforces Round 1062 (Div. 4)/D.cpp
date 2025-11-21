#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
vector<int> pri;
bool not_prime[N];

void pre(int N) {
  for (int i = 2; i <= N; ++i) {
    if (!not_prime[i]) {
      pri.push_back(i);
    }
    for (int pri_j : pri) {
      if (i > N / pri_j) break;
      not_prime[i * pri_j] = true;
      if (i % pri_j == 0) {
        break;
      }
    }
  }
}

void solve() {
    int n;
    cin >> n;
    int ans = 2;
    vector<ll> num(n);
    for(auto& i : num) cin >> i;
    for(auto i : pri) {
        bool isvalue = false;
        for(auto j : num) {
            if(j % i) {
                isvalue = true;
                break;
            }
        }
        if(isvalue) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    pre(1000);
    while(t--) solve();

    return 0;
}