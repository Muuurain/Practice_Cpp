#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    int aim = a / b;
    int ans;
    if(aim >= n) ans = 1;
    else {
        if(b == a) ans = 1;
        else ans = 2;
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