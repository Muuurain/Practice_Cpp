// template_pre_standard

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int p = n;
    int now = 1;
    int times = 0;
    vector<int> vis(n + 5);
    while(p > 1) {
        if(vis[now]);
        else {
            times++;
            if(times == m) {
                vis[now] = 1;
                p--;
                times = 0;
            }
        }
        now++;
        if(now == n + 1) {
            now = 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) cout << i << '\n';
    }

    return 0;
}