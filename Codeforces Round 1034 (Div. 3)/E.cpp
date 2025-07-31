#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> num(n + 10);
    vector<int> back_sum(n + 10);
    vector<int> front_sum(n + 10);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        num[a[i]]++;
    }
    for(int i = n; i >= 0; i--) {
        back_sum[i] = num[i];
        back_sum[i] += back_sum[i + 1];
    }
    front_sum[0] = num[0];
    for(int i = 1; i <= n; i++) {
        front_sum[i] = num[i];
        front_sum[i] += front_sum[i - 1];
    }
    int mex = 0;
    while(num[mex]) mex++;
    vector<int> ret(n + 1);
        // ret[0] = 1;
        // ret[n] = 1;
    for(int i = num[0]; i <= back_sum[0]; i++) {
        ret[i]++;
    }
    for(int i = mex; i > 0; i--) {
        for(int j = num[i]; j <= back_sum[i] + front_sum[i - 1] - i; j++) {
            ret[j]++;
        }
    }
    for(int i = 0; i <= n; i++) {
        cout << ret[i] << " ";
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}