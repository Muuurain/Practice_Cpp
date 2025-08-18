#include <bits/stdc++.h>
using namespace std;

int n;
int ans = INT_MAX;
struct food{
    int s;
    int b;
}f[12];
void dfs(int index, int ss, int sb) {
    if(index) ans = min(ans, abs(ss - sb));
    for(int i = index + 1; i <= n; i++) {
        dfs(i, ss * f[i].s, sb + f[i].b);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> f[i].s >> f[i].b;
    }
    dfs(0, 1, 0);
    cout  << ans << endl;

    return 0;
}