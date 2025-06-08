#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int n0[n + 10] = {0};
        int m0[m + 10] = {0};
        for(int i = 0; i < n; i++) {
            scanf("%d", &n0[i]);
        }
        for(int i = 0; i < m; i++) {
            scanf("%d", &m0[i]);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(n0[i] >= m0[cnt]) {
                if(cnt != m - 1) {
                    cnt++;
                }
                else {
                    cnt = m;
                    break;
                }
            }
        }
        int ret = 0;
        if(cnt == m) {
            printf("%d\n", ret);
            continue;
        }
        else {
            ret = m0[cnt];
            int temp = cnt;
            cnt = 0;
            int value = 0;
            for(int i = 0; i < n; i++) {
                if(cnt == temp) {
                    cnt++;
                    i--;
                    continue;
                }
                else if(cnt == m) {
                    printf("%d\n", cnt);
                    value = 1;
                    break;
                }
                else {
                    if(n0[i] >= m0[cnt]) {
                        cnt++;
                    }
                }
            }
            if(!value) {
                printf("-1\n");
            }
        }
    }

    return 0;
}