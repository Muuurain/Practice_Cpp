#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    if(s[0] > '0' && s[0] < '9') cout << "https://www.luogu.com.cn/problem/P" << s << endl;
    else cout << "https://www.luogu.com.cn/problem/" << s << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;;
}