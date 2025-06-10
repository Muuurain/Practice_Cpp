#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> ar;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ar.push_back(t);
    }
    set<int> cur, seen;
    int ret = 0;;
    for(int i = 0; i < n; i++) {
        cur.insert(ar[i]);
        seen.insert(ar[i]);
        if(cur.size() == seen.size()) {
            ret++;
            seen.clear();
        }
    }
    cout << ret << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}