#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    int a, b, c;
    int ret;
    cin >> n;
    
    cout << "1 01" << endl;
    cout.flush();
    cin >> a;
    assert(a != -1);

    cout << "1 00" << endl;
    cout.flush();
    cin >> b;
    assert(b != -1);

    cout << "1 0" << endl;
    cout.flush();
    cin >> c;
    assert(c != -1);

    if(c == a + b) cout << "0 " << n << " 1" << endl;
    else cout << "0 " << n << " 0" << endl;
    cout.flush();
    cin >> ret;
    assert(ret != -1);
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