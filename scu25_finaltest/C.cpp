#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, q;
    cin >> n >> a >> q;
    string s;
    cin >> s;

    int p = 0;
    for (char c : s) {
        if (c == '+') {
            p++;
        }
    }
    if (a + p < n) {
        cout << "NO\n";
        return;
    }
    int current = a;
    bool found = (current == n);
    for (char c : s) {
        if (c == '+') {
            current++;
        } 
        else {
            current--;
        }
        if (current == n) {
            found = true;
            break;
        }
    }
    if (found) {
        cout << "YES\n";
    } 
    else {
        cout << "MAYBE\n";
    }
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