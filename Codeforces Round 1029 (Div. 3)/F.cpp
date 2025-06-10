#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    bool value = 1;
    vector< vector<int> > edge(n + 1);
    for(int i = 1; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        edge[t1].push_back(t2);
    }
    int index = 0;
    long long ret = 0;
    int root = 0;
    for(int i = 1; i <= n; i++) {
        if(edge[i].size() == 0) {
            root++;
            if(root > 2) {
                value = 0;
                break;
            }
        }
    }
    if(!value) {
        cout << ret << endl;
        return;
    }
    for(int i = 0)
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}