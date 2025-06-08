#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        scanf("%d%d", &n, &x);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(i != x) {
                printf("%d ", i);
                cnt++;
            }
            else {
                continue;
            }
        }
        if(cnt != n) {
            printf("%d\n", x);
        }
        else {
            printf("\n");
        }
    }

    return 0;
}