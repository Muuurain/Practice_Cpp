#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> odd, even;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if(t & 1) odd.push_back(t);
        else even.push_back(t);
    }
    sort(odd.begin(), odd.end());
    ll ret = 0;
    if(odd.size()) {
        for(int i : even) ret += i;
    }
    for(int i = odd.size() / 2; i < odd.size(); i++) {
        ret += odd[i];
    }
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