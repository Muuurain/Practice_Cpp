#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        int a[200010] = {0};
        memset(a, -1, sizeof(a));
        int b[200010] = {0};
        memset(b, -1, sizeof(b));
        int maxn = 0;
        int minn = 2000000000;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            maxn = max(maxn, a[i]);
            minn = min(minn, a[i]);
        }
        int value = -1;
        int temp = -1;
        int no = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            if(b[i] != -1) {
                value = i;
                if(temp == -1) {
                    temp = a[i] + b[i];
                }
                else {
                    int t2 = a[i] + b[i];
                    if(t2 != temp) {
                        no = 1;
                    }
                }
            }
        }
        if(no) {
            printf("0\n");
            continue;
        }
        int ret = maxn;
        int way = 0;
        if(value != -1) {
            ret = temp;
            for(int i = 0; i < n; i++) {
                b[i] = ret - a[i];
                if(b[i] > k || b[i] < 0) {
                    way--;
                }
            }
            way++;
            if(way < 0) {
                way = 0;
            }
        }
        else {
            way = minn + k - maxn + 1;
        }
        printf("%d\n", way);
    }

    return 0;
}