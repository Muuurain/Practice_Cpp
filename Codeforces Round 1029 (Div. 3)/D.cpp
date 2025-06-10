#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;
    int diff = arr[1] - arr[0];
    int invalue = 0;
    for(int i = 0; i < n - 1; i++) {
        if(arr[i + 1] - arr[i] != diff) {
            invalue = 1;
            break;
        }
    }
    if(invalue) {
        cout << "NO" << endl;
    }
    else {
        for(int i = 0; i < n; i++) arr[i] += (diff > 0 ? (-1 * diff * (i + 1)) : (diff * (n - i)));
        if(arr[0] >= 0 && arr[0] % (n + 1) == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}