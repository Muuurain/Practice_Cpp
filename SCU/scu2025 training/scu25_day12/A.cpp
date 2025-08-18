#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
bool vis[N];
vector<int> tvis;
int pa[N];
int ans = INT_MAX;
int cnt;
int find(int t) {
    cnt++;
    if(vis[t]) return INT_MAX;
    else tvis.push_back(t);
    if(pa[t] != t) return find(pa[t]);
    else return t;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        pa[i] = i;
    }
    for(int i = 1; i <= n; i++) {
        int t;
        tvis.clear();
        cnt = 0;
        cin >> t;
        if(find(t) == i) {
            ans = min(ans, cnt);
            for(auto i : tvis) vis[i] = true;
        }
        else pa[i] = t;
    }

    cout << ans << endl;
    return 0;
}