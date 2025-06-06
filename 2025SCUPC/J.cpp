#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        long long treedo = 0;
        bool value = true;
        for(int i = 0; i < n; i++) {
            long long temp;
            scanf("%lld", &temp);
            treedo += temp;
            if(i != 0) {
                treedo -= 2;
            }
            if(treedo < 0 && value) {
                printf("NO\n");
                value = false;
            }
            if(treedo == 0 && value && i != n - 1) {
                printf("NO\n");
                value = false;
            }
        }
        if(value) {
            if(treedo != 0) {
                printf("NO\n");
            }
            else {
                printf("Yes\n");
            }
        }
    }

    return 0;
}