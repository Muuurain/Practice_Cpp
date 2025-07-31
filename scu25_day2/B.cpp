#include <bits/stdc++.h>
using namespace std;

const int n = 1e6 + 20;
int tree[n];
long long sum;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int l = 0, r = 0;
    for(int i = 1; i <= N; i++) {
        cin >> tree[i];
        r = max(r, tree[i]);
    }
    int ans;
    while(l <= r) {
        sum = 0;
        int mid = (l + r) / 2;
        for(int i = 1; i <= N; i++) {
            if(tree[i] - mid > 0) {
                sum += tree[i] - mid;
            }
        }
        if(sum < M) {
            r = mid - 1;
        }
        else {
            ans = mid;
            l = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}