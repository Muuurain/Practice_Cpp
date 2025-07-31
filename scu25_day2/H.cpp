#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n + 10];
    int b[n + 10];
    int ret[n + 10];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    if(k == 1) {
        cout << "YES" << endl;
        return;
    }
    sort(b, b + n);
    int x = b[k - 2];
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] <= x) {
            ret[cnt++] = a[i]; 
        }
    }
    int l = 0, r = cnt - 1;
    while(l < r) {
        if(ret[l] == ret[r]) {
            l++;
            r--;
        }
        else {
            if(ret[l] == x) {
                l++;
                cnt--;
                if(l > r) {
                    cout << "NO" << endl;
                    return;
                }
            }
            else if(ret[r] == x) {
                r--;
                cnt--;
                if(l > r) {
                    cout << "NO" << endl;
                    return;
                }
            }
            else {
                cout << "NO" << endl;
                return;
            }
            if(cnt < k - 1) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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