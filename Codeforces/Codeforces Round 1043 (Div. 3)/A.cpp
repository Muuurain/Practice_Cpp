#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    string a = "";
    int n, m;
    cin >> n;
    cin >> a;
    cin >> m;
    string b = "", c = "";
    cin >> b >> c;
    int cnt = 0;
    for(auto i : c) {
        if(i == 'V') {
            char t = b[cnt++];
            a = t + a;
        }
        else {
            char t = b[cnt++];
            a += t;
        }
    }
    cout << a << '\n';
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