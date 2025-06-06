#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<long long> tree[300000];
int main() {
    ll n, d;
    cin >> n >> d;
    if(d < n - 1 || d > (n * (n - 1) / 2)) {
        cout << "NO" << endl;
        return 0;
    }
    else {
        cout << "YES" << endl;
        tree[0].push_back(1);
        long long temp = n - 1;
        long long cnt = 1;
        long long sum = d;
        while(1) {
            if(temp * cnt < sum) {
                tree[cnt].push_back(cnt + 1);
                sum -= cnt;
                cnt++;
                temp--;
            }
            else {
                if(temp * cnt == sum) {
                    for(long long i = cnt + 1; i <= n; i++) {
                        tree[cnt].push_back(i);
                    }
                    break;
                }
                else {
                    ll num1 = (sum + cnt - 1 - (cnt - 1) * (temp + 1));
                    long long i = 0;
                    long long t1 = 0;
                    for(i = cnt + 1, t1 = 0; t1 < num1; i++, t1++) {
                        tree[cnt].push_back(i);
                    }
                    ll num2 = temp - num1;
                    for(t1 = 0; t1 < num2; i++, t1++) {
                        tree[cnt - 1].push_back(i);
                    }
                    break;
                }
            }
        }
        for(long long i = 1; i <= cnt; i++) {
            // cout << tree[i].size() << "-------------------" << endl;
            for(long long j = 0; j < tree[i].size(); j++) {
                printf("%d %d\n", tree[i - 1][0], tree[i][j]);
            }
        }
        cout << "1" << endl;
    }

    return 0;
}