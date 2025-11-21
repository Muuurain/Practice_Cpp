#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> friends(n);
    for(auto &i : friends) cin >> i;
    sort(friends.begin(), friends.end());
    int l = 0, r = x;
    int m = (l + r) / 2;
    int ret = -1;
    while(l <= r) {
        int sum = 0;
        m = (l + r) / 2;
        if(n == 1) {
            sum += max(0, friends[0] - m + 1);
            sum += max(0, x - (friends[0] + m) + 1);
        }
        else {
            for(int i = 0; i < n; i++) {
                if(i == 0) {
                    sum += max(0, friends[i] - m + 1);
                }
                else if(i == n - 1) {
                    sum += max(0, friends[i] - m - (friends[i - 1] + m) + 1);
                    sum += max(0, x - (friends[i] + m) + 1);
                }
                else {
                    sum += max(0, friends[i] - m - (friends[i - 1] + m) + 1);
                }
            }
        }
        if(sum >= k) {
            l = m + 1;
            ret = m;
        }
        else {
            r = m - 1;
        }
    }
    m = ret;
    if(m == 0) {
        for(int i = 0; i < k; i++) {
            cout << i << ' ';
        }
    }
    else {
        if(n == 1) {
            for(int i = 0; i <= friends[0] - m && k; i++) {
                cout << i << ' ';
                k--;
            }
            for(int i = friends[0] + m; i <= x && k; i++) {
                cout << i << ' ';
                k--;
            }
        }
        else {
            for(int i = 0; i < n; i++) {
                if(i == 0) {
                    if(friends[i] - m + 1 > 0) {
                        for(int j = 0; j <= friends[i] - m && k; j++) {
                            cout << j << ' ';
                            k--;
                        }
                    }
                }
                else if(i == n - 1) {
                    if(friends[i] - m - (friends[i - 1] + m) + 1 > 0) {
                        for(int j = friends[i - 1] + m; j <= friends[i] - m && k; j++) {
                            cout << j << ' ';
                            k--;
                        }
                    }
                    for(int j = friends[i] + m; j <= x && k; j++) {
                        cout << j << ' ';
                        k--;
                    }
                }
                else {
                    if(friends[i] - m - (friends[i - 1] + m) + 1 > 0) {
                        for(int j = friends[i - 1] + m; j <= friends[i] - m && k; j++) {
                            cout << j << ' ';
                            k--;
                        }
                    }
                }
                if(!k) break;
            }
        }
    }
        cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}