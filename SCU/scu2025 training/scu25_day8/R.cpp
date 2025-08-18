#include <bits/stdc++.h>
using namespace std;
const int n = 1e7 + 10;
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
void solve() {
    int N;
    cin >> N;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}