#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int ret[n + 1];
        memset(ret, -1, sizeof(ret));
        // int post[n + 1] = {0};
        // for(int i = 1; i <= n; i++) {
        //     post[i] = n - i + 1;
        // }
        int action[m];
        int times[100100] = {0};
        for(int i = 0; i < m; i++) {
            scanf("%d", &action[i]);
        }
        int cnt = n;
        int time = 0;
        for(int i = 0; i < m; i++) {
            time++;
            if(times[action[i]] == 0) {
                times[action[i]]++;
                ret[cnt--] = time;
            }
        }
        for(int i = 1; i <= n; i++) {
            printf("%d", ret[i]);
            if(i != n) {
                printf(" ");
            }
            else {
                printf("\n");
            }
        }
        
        
    }

    return 0;
}