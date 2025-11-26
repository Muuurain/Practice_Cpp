#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> num(n);
    for(auto& i : num) cin >> i;
    vector<int> ans(n);
    auto ps = num.begin();
    auto pe = num.end() - 1;
    for(int i = n - 1; i >= 0;) {
        ans[i--] = *ps;
        ps++;
        if(i == -1) break;
        ans[i--] = *pe;
        pe--;
    }
    for(auto i : ans) cout << i << ' ';
    cout << '\n';
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