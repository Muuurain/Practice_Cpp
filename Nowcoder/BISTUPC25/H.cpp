#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> num(n);
    for(auto& i : num) cin >> i;

    vector<pair<int, int> > seg;
    for(int i = 0; i < n; i++) {
        int l = i - num[i] + 1;
        if(l >= 0 && num[i] >= num[l]) {
            seg.push_back({l, i});
        }
        int r = i + num[i] - 1;
        if(r < n && num[i] >= num[r]) {
            seg.push_back({i, r});
        }
    }

    sort(seg.begin(), seg.end(), [&](pair<int, int>& a, pair<int, int>& b) {
        if(a.first != b.first) return a.first < b.first;
        else return a.second > b.second;
    });
    int st = 0;
    int p = 0;
    int ans = 0;
    while(st < n) {
        int maxr = -1;
        while(p < seg.size() && seg[p].first <= st) {
            maxr = max(maxr, seg[p].second);
            p++;
        }
        if(maxr < st) {
            cout << -1 << '\n';
            return;
        }
        else {
            ans++;
            st = maxr + 1;
        }
    }
    cout << ans << '\n';
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