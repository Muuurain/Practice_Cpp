#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    int maxnum = 0;
    int start = 0;

    vector<int> path(n + 1);
    for(int i = 1; i <= n; i++) {
        cout << "? " << i << " " << n;
        for(int j = 1; j <= n; j++) cout << " " << j;
        cout << '\n';
        cout.flush();
        int num;
        cin >> num;
        assert(num != -1);
        path[i] = num;
        if(maxnum < num) {
            maxnum = num;
            start = i;
        }
    }

    vector<int> ans;
    ans.push_back(start);
    int cur = start;

    while(path[cur] > 1) {
        for(int i = 1; i <= n; i++) {
            if(path[i] == path[cur] - 1) {
                cout << "? " << cur << " 2 " << cur << " " << i << '\n';
                cout.flush();
                int num;

                
                cin >> num;
                assert(num != -1);
                if(num == 2) {
                    cur = i;
                    ans.push_back(i);
                    break;
                }
            }
        }
    }
    
    cout << "! " << ans.size();
    for(int i : ans) cout << " " << i;
    cout << '\n';
    cout.flush();
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