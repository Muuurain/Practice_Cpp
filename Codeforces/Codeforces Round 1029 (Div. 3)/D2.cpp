#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr) cin >> i;
    if(((n - 1) * arr[0] - n * arr[1]) % ((n - 1) - 2 * n) != 0 || (arr[1] - (2 * arr[0])) % ((n - 1) - 2 * n) != 0) {
        cout << "NO" << endl;
        return;
    }
    int x = ((n - 1) * arr[0] - n * arr[1]) / ((n - 1) - 2 * n);
    int y = (arr[1] - (2 * arr[0])) / ((n - 1) - 2 * n);
    if(x < 0 || y < 0) {
        cout << "NO" <<endl;
        return; 
    }
    for(int i = 0; i < n; i++) {
        arr[i] -= x * (i + 1) + y * (n - i);
        if(arr[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}