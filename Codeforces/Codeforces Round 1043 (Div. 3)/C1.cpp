#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    ll n;
    cin >> n;
    ll spend = 0;
    while(n) {
        ll cnt = log10(n) / log10(3);
        n -= pow(3, cnt);
        if(!cnt) {
            spend += 3;
            continue;
        }
        spend += pow(3, cnt + 1) + cnt * pow(3, cnt - 1);
    } 


    cout << spend << "\n";
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