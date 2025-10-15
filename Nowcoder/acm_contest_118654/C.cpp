#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 10;
vector<int> pri;
bool not_prime[N];

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
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    pre(N);
    int step = 1;
    while(true) {
        ll ret = 0;
        ll temp = 1;
        for(int index = 0; index < pri.size(); index++) {
            int i = pri[index];
            if (i * i > n) {
                break;
            }
            else {
                if(n % i == 0) {
                    ll t = n;
                    int count = 1;
                    while(t % i == 0) {
                        t /= i;
                        count++;
                    }
                    temp *= count;
                    if(t != 1) {
                        for(auto &j : pri) {
                            if(j * j > n) break;
                            while(t % j == 0) t /= j;
                        }
                        if(t != 1) {
                            temp *= 2;
                            pri.push_back(t);
                        }
                    }
                }
            }
        }
        if(temp == 1) {
            break;   
        }
        step++;
        n = temp;
    }
    cout << step << '\n';

    return 0;
}