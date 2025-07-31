#include<bits/stdc++.h>
using namespace std;

int h[10010], diff[10010], prefix[10010];
map<pair<int, int>, bool> vis;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, I, H, R;
    cin >> N >> I >> H >> R;
    diff[1] = H;
    // for(int i = 1; i <= N; i++) prefix[i] = prefix[i - 1] + h[i];
    for(int i = 0; i < R; i++) {
        int l, r;
        cin >> l >> r;
        if(l > r) {
            swap(l, r);
        }
        if(!vis[{l, r}]) {
            diff[l + 1]--;
            diff[r]++;
        }
        vis[{l, r}] = true;
    }
    for(int i = 1; i <= N; i++) prefix[i] = prefix[i - 1] + diff[i];
    for(int i = 1; i <= N; i++) cout << prefix[i] << '\n';
    return 0;
}