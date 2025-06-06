#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll x1, x2, x3;
        scanf("%d%d%d", &x1, &x2, &x3);
        ll sum = x1 + x2 + x3;
        ll avg = sum / 3;
        if(avg * 3 != sum) {
            printf("-1\n");
            continue;
        }
        else {
            int value = 1;
            ll aim[4] = {0};
            ll ret[4] = {0};
            aim[1] = (x1 - avg);
            if(aim[1] & 1) {
                value = 0;
            }
            ret[1] = aim[1] / 2;
            aim[2] = (x2 - avg);
            if(aim[2] & 1) {
                value = 0;
            }
            ret[2] = aim[2] / 2;
            aim[3] = (x3 - avg);
            if(aim[3] & 1) {
                value = 0;
            }
            ret[3] = aim[3] / 2;
            if(value) {
                if(ret[1] + ret[2] + ret[3] == 0) {
                    int ret0 = 0;
                    for(int i = 1; i <= 3; i++) {
                        if(ret[i] > 0) {
                            ret0 += ret[i];
                        }
                    }
                    printf("%d\n", ret0);
                }
                else {
                    printf("-1\n");
                }
            }
            else {
                printf("-1\n");
            }
        }
        
    }

    return 0;
}