#include <bits/stdc++.h>
using namespace std;
const int n = 1e8 + 10;
vector<int> pri;
bool not_prime[n];
int N, K;
int ans;
int num[30];
void pre() {
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
void dfs(int node, int sum, int k) {
    if(k == K) {
        if(!not_prime[sum]) ans++;
        return;
    }
    for(int i = node + 1; i < N; i++) {
        dfs(i, sum + num[node], k + 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pre();
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    for(int i = 1; i + K - 1 <= N; i++) {
        dfs(i, 0, 0);
    }
    cout << ans << endl;

    return 0;
}