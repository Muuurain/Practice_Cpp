#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> num(n);
    vector<int> uniq(n);
    for (int i = 0; i < n; ++i) {
        cin >> uniq[i];
    }
    num = uniq;

    sort(uniq.begin(), uniq.end());
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
    uniq.shrink_to_fit();

    vector<int> occ(uniq.size());
    
    for(auto& x : num) {
        x = lower_bound(uniq.begin(), uniq.end(), x) - uniq.begin();
        occ[x]++;
    }

    for(auto i : occ) {
        if(i % k) {
            cout << 0 << '\n';
            return;
        }
    }

    ll ret = 0;

    int p1 = 0, p2 = 0;
    vector<int> nowset(uniq.size());
    vector<int> aimset(uniq.size());

    for(int i = 0; i < aimset.size(); i++) {
        aimset[i] = occ[i] / k;
    }

    int isvalue = true;
    while(p1 < n) {
        while (p2 < n && nowset[num[p2]] < aimset[num[p2]]) {
            nowset[num[p2]]++;
            ret++;
            p2++;
        }
        ret += p2 - p1 - 1;
        nowset[num[p1]]--;
        p1++;
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