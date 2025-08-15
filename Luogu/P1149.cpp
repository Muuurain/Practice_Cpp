#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int cost[N] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ans[25];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 10; i < N; i++) {
        int t = i;
        while(t) {
            cost[i] += cost[t % 10];
            t /= 10;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j + i < N; j++) {
            int sum = cost[i] + cost[j] + cost[i + j] + 4;
            ans[sum]++;
        }
    }

    int n;
    cin >> n;
    cout << ans[n] << endl;

    return 0;
}