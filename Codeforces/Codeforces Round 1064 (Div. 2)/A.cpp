#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int ans = 0;
    for(int i = n - 2; i >= 0; i--) {
        if(s[i] != s[i + 1]) {
            s[i] = s[i + 1];
            ans++;
        }
    }
    cout << ans << '\n';
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