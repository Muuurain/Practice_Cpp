#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    pre(N);
    vector<int> ans(N);
    ans[1] = 1;
    for(int i = 2; i < N; i++) {
        if(not_prime[i]) ans[i] = ans[i - 1];
        else ans[i] = ans[i - 1] + 1;
    }
    while(t--) {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }

    return 0;
}