#include <bits/stdc++.h>

using namespace std;

int ret[1000];
int main() {
    int m, n;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        ret[t]++;
    }
    for(int i = 1; i <= n; i++) {
        while(ret[i]--) {
            printf("%d ", i);
        }
    }
    cout << endl;

    return 0;
}