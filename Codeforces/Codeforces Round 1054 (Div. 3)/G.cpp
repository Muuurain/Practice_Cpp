#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);

    vector<int> uniq;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        uniq.push_back(a[i]);
    }
    sort(uniq.begin(), uniq.end());
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(uniq.begin(), uniq.end(), a[i]) - uniq.begin();
    }
    
    vector<vector<int> > pos(n);
    for(int i = 0; i < n; i++) {
        pos[a[i]].push_back(i);
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int len = r - l + 1;
        int aim = len / 3;
        int k = 50;
        vector<int> ans;
        while(k--) {
            int aimpos = rng() % len + l;
            int tl = lower_bound(pos[a[aimpos]].begin(), pos[a[aimpos]].end(), l) - pos[a[aimpos]].begin();
            int tr = upper_bound(pos[a[aimpos]].begin(), pos[a[aimpos]].end(), r) - pos[a[aimpos]].begin();
            if(tr - tl > aim) {
                if(ans.empty() || (ans[0] != uniq[a[aimpos]] && ans.size() == 1)) ans.push_back(uniq[a[aimpos]]);
            }
        }
        if(ans.size() == 0) cout << -1 << '\n';
        else {
            sort(ans.begin(), ans.end());
            for(auto i : ans) cout << i << ' ';
            cout << '\n';
        }
    }
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