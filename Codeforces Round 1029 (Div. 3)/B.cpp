#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        int cnt = 1;
        if(n & 1)  {
            for(int i = 0; i <= n / 2; i++){
                printf("%d ",cnt);
                cnt += 2;
            }
            cnt -= 2;
            cnt -= 1;
            for(int i = 0; i < n / 2; i++) {
                printf("%d ", cnt);
                cnt -= 2;
            }
            printf("\n");
        }
        else{
            for(int i = 0; i < n / 2; i++) {
                printf("%d ", cnt);
                cnt += 2;
            }
            cnt -= 2;
            cnt += 1;
            for(int i = 0; i < n / 2; i++) {
                printf("%d ", cnt);
                cnt -= 2;
            }
            printf("\n");
        }
    }

    return 0;
}