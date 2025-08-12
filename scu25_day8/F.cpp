#include <bits/stdc++.h>
using namespace std;

const int n = 1e8 + 10;
vector<int> pri;
bool not_prime[n];

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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, q;
    cin >> N >> q;
    pre(N);
    while(q--) {
        int k;
        cin >> k;
        cout << pri[k - 1] << '\n';
    }

    return 0;
}