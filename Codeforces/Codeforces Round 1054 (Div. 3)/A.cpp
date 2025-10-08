#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    int ret = 0;
    int re = 0;
    while(n--) {
        int t;
        cin >> t;
        if(t == -1) re++;
        else if(t == 0) {
            ret++;
        }
    }
    if(re & 1) ret += 2;
    cout << ret << '\n';
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