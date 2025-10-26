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

    if(uniq.size() % k) {
        cout << 0 << '\n';
        return;
    }

    int count = n / uniq.size();
    for(auto i : occ) {
        if(i != count) {
            cout << 0 << '\n';
            return;
        }
    }

    ll ret = 0;

    int p1 = 0, p2 = 0;
    vector<int> aimset(uniq.size());
    int isvalue = true;
    while(p1 < n) {
        while (p2 < n && aimset[num[p2]] < count) {
            aimset[num[p2]]++;
            ret++;
            p2++;
        }
        ret += p2 - p1 - 1;
        aimset[num[p1]]--;
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