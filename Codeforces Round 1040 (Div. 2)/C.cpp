#include <bits/stdc++.h>
using namespace std;

const int N = 6e3 + 10;
void solve() {
    int n;
    cin >> n;
    int vis[N] = {0};
    int a[N] = {0}, b[N] = {0};
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    for(int i = 1; i <= n; i++) {
        int value = 1;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            else if(a[i] >= a[j] && b[i] <= b[j]) {
                value = 0;
                break;
            }
        }
        if(value) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(int i : ans) cout << i << " ";
    cout << endl;
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