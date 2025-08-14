#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    long long sum1 = 0,  sum2 = 0;
    while(n--) {
        int t;
        cin >> t;
        sum1 += t;
    }
    while(m--) {
        int t;
        cin >> t;
        sum2 += t;
    }
    if(sum1 > sum2) {
        cout << "Tsondu" << endl;
    }
    else if(sum1 < sum2) {
        cout << "Tenzing" << endl;
    }
    else {
        cout << "Draw" << endl;
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