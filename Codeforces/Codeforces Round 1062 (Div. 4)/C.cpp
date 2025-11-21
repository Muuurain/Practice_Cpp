#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> num(n);
    bool hveven = false, hvodd = false;
    for(auto& i : num) {
        cin >> i;
        if(i & 1) hvodd = true;
        else hveven = true;
    }
    if(hvodd && hveven) sort(num.begin(), num.end());
    for(auto i : num) cout << i << ' ';
    cout << '\n';
    
    
    return;
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