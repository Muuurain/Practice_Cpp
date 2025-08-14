#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;
    unordered_map<int, int> orbit;
    while(n--) {
        int x;
        cin >> x;
        orbit[x]++;
    }
    long long ans = 0;
    for(auto &it : orbit) {
        ans += min(it.second, c);
    }
    cout << ans << endl;
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